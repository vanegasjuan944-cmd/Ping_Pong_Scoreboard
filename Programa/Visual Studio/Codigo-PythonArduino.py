import cv2
import numpy as np

cap = cv2.VideoCapture(0)

# Rango de color de la pelota (ajustar según tu pelota)
COLOR_BAJO = np.array([100, 100, 100])
COLOR_ALTO = np.array([130, 255, 255])
UMBRAL_MESA_Y = 420   # Altura en píxeles donde está la superficie de la mesa

PUNTOS_SET = 11

# Variables de seguimiento de pelota
last_x, last_y = None, None
botes_izq = 0
botes_der = 0
esperando_rebote = False
punto_anotado = False

# Marcador
puntos_j1 = 0
puntos_j2 = 0
sets_j1 = 0
sets_j2 = 0
sets_jugados = 0  # Determina qué etiqueta va a la izquierda en el marcador


def mostrar_marcador():
    # En sets pares: J1 a la izquierda. En sets impares: J2 a la izquierda.
    if sets_jugados % 2 == 0:
        print(f"J1 {puntos_j1:02} ({sets_j1}) - ({sets_j2}) {puntos_j2:02} J2")
    else:
        print(f"J2 {puntos_j2:02} ({sets_j2}) - ({sets_j1}) {puntos_j1:02} J1")


def sumar_punto(jugador):
    global puntos_j1, puntos_j2, sets_j1, sets_j2, sets_jugados

    if jugador == 1:
        puntos_j1 += 1
    else:
        puntos_j2 += 1

    if puntos_j1 >= PUNTOS_SET:
        sets_j1 += 1
        sets_jugados += 1
        puntos_j1 = 0
        puntos_j2 = 0
        print(f"--- SET PARA J1 | Sets: J1 {sets_j1} - {sets_j2} J2 ---")
    elif puntos_j2 >= PUNTOS_SET:
        sets_j2 += 1
        sets_jugados += 1
        puntos_j1 = 0
        puntos_j2 = 0
        print(f"--- SET PARA J2 | Sets: J1 {sets_j1} - {sets_j2} J2 ---")

    mostrar_marcador()


def anotar_punto(jugador_pantalla, motivo):
    global botes_izq, botes_der, esperando_rebote, punto_anotado

    # Si estamos en un set impar, los lados físicos están invertidos
    if sets_jugados % 2 == 1:
        jugador_pantalla = 2 if jugador_pantalla == 1 else 1

    print(f"PUNTO J{jugador_pantalla} ({motivo})")
    sumar_punto(jugador_pantalla)

    botes_izq = 0
    botes_der = 0
    esperando_rebote = False
    punto_anotado = True


def reset_jugada():
    global last_x, last_y, botes_izq, botes_der, esperando_rebote, punto_anotado
    last_x, last_y = None, None
    botes_izq = 0
    botes_der = 0
    esperando_rebote = False
    punto_anotado = False


while True:
    ret, frame = cap.read()
    if not ret:
        break

    frame = cv2.flip(frame, 1)
    h, w = frame.shape[:2]
    centro_x = w // 2

    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    mask = cv2.inRange(hsv, COLOR_BAJO, COLOR_ALTO)
    mask = cv2.erode(mask, None, iterations=2)
    mask = cv2.dilate(mask, None, iterations=2)

    contornos, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    pelota_visible = False

    if contornos:
        c = max(contornos, key=cv2.contourArea)
        ((x, y), radio) = cv2.minEnclosingCircle(c)

        if radio > 8:
            pelota_visible = True
            cv2.circle(frame, (int(x), int(y)), int(radio), (0, 255, 0), 2)

            if not punto_anotado:
                base_pelota = y + radio

                if base_pelota >= UMBRAL_MESA_Y and not esperando_rebote:
                    esperando_rebote = True

                if esperando_rebote and last_y is not None:
                    if y < last_y:
                        if x < centro_x:
                            botes_izq += 1
                            botes_der = 0
                        else:
                            botes_der += 1
                            botes_izq = 0
                        esperando_rebote = False
                    elif y > last_y + 5:
                        if x < centro_x:
                            anotar_punto(2, "Pelota pasó de largo en IZQ")
                        else:
                            anotar_punto(1, "Pelota pasó de largo en DER")

                if botes_izq >= 2:
                    anotar_punto(2, "Doble bote en IZQ")
                elif botes_der >= 2:
                    anotar_punto(1, "Doble bote en DER")

            last_x, last_y = x, y

    if not pelota_visible and last_x is not None:
        if not punto_anotado:
            if last_x < 50 and botes_izq == 0:
                anotar_punto(1, "Salida sin rebote por IZQ")
            elif last_x > w - 50 and botes_der == 0:
                anotar_punto(2, "Salida sin rebote por DER")
            elif last_x < 50 and botes_izq == 1:
                anotar_punto(2, "Un rebote válido en IZQ")
            elif last_x > w - 50 and botes_der == 1:
                anotar_punto(1, "Un rebote válido en DER")
        reset_jugada()

    cv2.line(frame, (centro_x, 0), (centro_x, h), (255, 255, 255), 1)
    cv2.line(frame, (0, UMBRAL_MESA_Y), (w, UMBRAL_MESA_Y), (0, 255, 255), 2)

    cv2.imshow("Identificador", frame)
    if cv2.waitKey(1) == 27:
        break

cap.release()
cv2.destroyAllWindows()