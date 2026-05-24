#include "LedControl.h"
// LedControl(DIN, CLK, CS, 1)
LedControl lc=LedControl(11,12,10,1); // Objeto J1
LedControl lcc=LedControl(7,12,9,1); // Objeto Set
LedControl lccc=LedControl(6,12,8,1); // Objeto J2
#define demora 1000

byte vacio[8]= {     // Vacío
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

byte cero[8]= {    // Cero
  B00111100,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B00111100
};

byte uno[8]= {     // Uno
  B00010000,
  B00110000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00111000
};

byte dos[8]= {     // Dos
  B00111000,
  B01000100,
  B00000100,
  B00001000,
  B00010000,
  B00100000,
  B01000000,
  B01111100
};

byte tres[8]= {    // Tres
  B00111100,
  B01000010,
  B00000010,
  B00001100,
  B00000010,
  B00000010,
  B01000010,
  B00111100
};

byte cuatro[8]= {    // Cuatro
  B00000100,
  B00001100,
  B00010100,
  B00100100,
  B01000100,
  B01111110,
  B00000100,
  B00000100
};

byte cinco[8]= {     // Cinco
  B01111110,
  B01000000,
  B01000000,
  B01111100,
  B00000010,
  B00000010,
  B01000010,
  B00111100
};

byte seis[8]= {    // Seis
  B00111100,
  B01000010,
  B01000000,
  B01111100,
  B01000010,
  B01000010,
  B01000010,
  B00111100
};

byte siete[8]= {     // Siete
  B01111110,
  B00000010,
  B00000010,
  B00000100,
  B00001000,
  B00010000,
  B00100000,
  B00100000
};

byte ocho[8]= {    // Ocho
  B00111100,
  B01000010,
  B01000010,
  B00111100,
  B01000010,
  B01000010,
  B01000010,
  B00111100
};

byte nueve[8]= {     // Nueve
  B00111100,
  B01000010,
  B01000010,
  B01000010,
  B00111110,
  B00000010,
  B01000010,
  B00111100
};

byte diez[8]= {     // Diez
  B01000110,
  B11001001,
  B01001001,
  B01001001,
  B01001001,
  B01001001,
  B01001001,
  B11100110
};

byte once[8]= {     // Once
  B01000010,
  B11000110,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B11100111
};

byte doce[8]= {     // Doce
  B01000110,
  B11001001,
  B01000001,
  B01000001,
  B01000010,
  B01000100,
  B01001000,
  B11101111
};

byte trece[8]= {     // Trece
  B01000110,
  B11001001,
  B01000001,
  B01000110,
  B01000001,
  B01000001,
  B01001001,
  B11100110
};

byte catorce[8]= {     // Catorce
  B01000010,
  B11000110,
  B01001010,
  B01001010,
  B01010010,
  B01011111,
  B01000010,
  B11100010
};

byte quince[8]= {     // Quince
  B01001111,
  B11001000,
  B01001000,
  B01001110,
  B01000001,
  B01000001,
  B01000001,
  B11101110
};

byte dieciseis[8]= {     // Dieciseis
  B01000110,
  B11001001,
  B01001000,
  B01001110,
  B01001001,
  B01001001,
  B01001001,
  B11100110
};

byte diecisiete[8]= {     // Diecisiete
  B01001111,
  B11000001,
  B01000001,
  B01000010,
  B01000100,
  B01001000,
  B01001000,
  B11101000
};

byte dieciocho[8]= {     // Dieciocho
  B01000110,
  B11001001,
  B01001001,
  B01000110,
  B01001001,
  B01001001,
  B01001001,
  B11100110
};

byte diecinueve[8]= {     // Diecinueve
  B01000110,
  B11001001,
  B01001001,
  B01001001,
  B01000111,
  B01000001,
  B01001001,
  B11100110
};

byte unoJ1[8]= {     // 1 Set J1
  B10010000,
  B00110000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00111000
};

byte unoJ2[8]= {     // 1 Set J2
  B00010001,
  B00110000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00111000
};

byte dosJ1[8]= {     // 2 Sets J1
  B10011000,
  B10100100,
  B00000100,
  B00001000,
  B00010000,
  B00100000,
  B00100000,
  B00111100
};

byte dosEmp[8]= {     // 1 Set J1, 1 Set J2
  B10011001,
  B00100100,
  B00000100,
  B00001000,
  B00010000,
  B00100000,
  B00100000,
  B00111100
};

byte dosJ2[8]= {     // 2 Sets J2
  B00011001,
  B00100101,
  B00000100,
  B00001000,
  B00010000,
  B00100000,
  B00100000,
  B00111100
};

byte tresJ1[8]= {    // 3 Sets J1
  B10011000,
  B10100100,
  B10000100,
  B00011000,
  B00000100,
  B00000100,
  B00100100,
  B00011000
};

byte tresTopJ1[8]= {    // 2 Sets J1 1 Set J2
  B10011001,
  B10100100,
  B00000100,
  B00011000,
  B00000100,
  B00000100,
  B00100100,
  B00011000
};

byte tresTopJ2[8]= {    // 2 Sets J2 1 Set J1
  B10011001,
  B00100101,
  B00000100,
  B00011000,
  B00000100,
  B00000100,
  B00100100,
  B00011000
};

byte tresJ2[8]= {    // 3 Sets J2
  B00011001,
  B00100101,
  B00000101,
  B00011000,
  B00000100,
  B00000100,
  B00100100,
  B00011000
};

byte cuatroJ1[8]= {    // 3 Sets J1 1 Set J2
  B10000101,
  B10001100,
  B10010100,
  B00100100,
  B01000100,
  B01111110,
  B00000100,
  B00000100
};

byte cuatroEmp[8]= {    // 2 Sets J1 2 Sets J2
  B10000101,
  B10001101,
  B00010100,
  B00100100,
  B01000100,
  B01111110,
  B00000100,
  B00000100
};

byte cuatroJ2[8]= {    // 3 Sets J2 1 Set J1
  B10000101,
  B00001101,
  B00010101,
  B00100100,
  B01000100,
  B01111110,
  B00000100,
  B00000100
};

byte cincoJ1[8]= {     // 3 Sets J1 2 Sets J2
  B10111101,
  B10100001,
  B10100000,
  B00111000,
  B00000100,
  B00000100,
  B00100100,
  B00011000
};

byte cincoJ2[8]= {     // 3 Sets J2 2 Sets J1
  B10111101,
  B10100001,
  B00100001,
  B00111000,
  B00000100,
  B00000100,
  B00100100,
  B00011000
};




void mostrar_10(){     // Mostrar Vacío Set
  for (int i = 0; i < 8; i++){
    lcc.setRow(0,i,vacio[i]);
  }
}

void mostrar_0(){     // Mostrar 0 J1
  for (int i = 0; i < 8; i++){
    lc.setRow(0,i,cero[i]);
  }
}
void mostrar_000(){     // Mostrar 0 Set
  for (int i = 0; i < 8; i++){
    lcc.setRow(0,i,cero[i]);
  }
}
void mostrar_0000(){     // Mostrar 0 J2
  for (int i = 0; i < 8; i++){
    lccc.setRow(0,i,cero[i]);
  }
}

void mostrar_1(){     // Mostrar 1 J1
  for (int i = 0; i < 8; i++){
    lc.setRow(0,i,uno[i]);
  }
}
void mostrar_111(){     // Mostrar 1 Set J1
  for (int i = 0; i < 8; i++){
    lcc.setRow(0,i,unoJ1[i]);
  }
}
void mostrar_112(){     // Mostrar 1 Set J2
  for (int i = 0; i < 8; i++){
    lcc.setRow(0,i,unoJ2[i]);
  }
}
void mostrar_1111(){     // Mostrar 1 J2
  for (int i = 0; i < 8; i++){
    lccc.setRow(0,i,uno[i]);
  }
}

void mostrar_2(){     // Mostrar 2 J1
  for (int i = 0; i < 8; i++){
    lc.setRow(0,i,dos[i]);
  }
}
void mostrar_221(){     // Mostrar 2 Sets J1
  for (int i = 0; i < 8; i++){
    lcc.setRow(0,i,dosJ1[i]);
  }
}
void mostrar_222(){     // Mostrar 1 Set J1 1 Set J2
  for (int i = 0; i < 8; i++){
    lcc.setRow(0,i,dosEmp[i]);
  }
}
void mostrar_223(){     // Mostrar 2 Sets J2
  for (int i = 0; i < 8; i++){
    lcc.setRow(0,i,dosJ2[i]);
  }
}
void mostrar_2222(){     // Mostrar 2 J2
  for (int i = 0; i < 8; i++){
    lccc.setRow(0,i,dos[i]);
  }
}

void mostrar_3(){     // Mostrar 3 J1
  for (int i = 0; i < 8; i++){
    lc.setRow(0,i,tres[i]);
  }
}
void mostrar_331(){     // Mostrar 3 Sets J1
  for (int i = 0; i < 8; i++){
    lcc.setRow(0,i,tresJ1[i]);
  }
}
void mostrar_332(){     // Mostrar 2 Sets J1 1 Set J2
  for (int i = 0; i < 8; i++){
    lcc.setRow(0,i,tresTopJ1[i]);
  }
}
void mostrar_333(){     // Mostrar 2 Sets J2 1 Set J1
  for (int i = 0; i < 8; i++){
    lcc.setRow(0,i,tresTopJ2[i]);
  }
}
void mostrar_334(){     // Mostrar 3 Sets J2
  for (int i = 0; i < 8; i++){
    lcc.setRow(0,i,tresJ2[i]);
  }
}
void mostrar_3333(){     // Mostrar 3 J2
  for (int i = 0; i < 8; i++){
    lccc.setRow(0,i,tres[i]);
  }
}

void mostrar_4(){     // Mostrar 4 J1
  for (int i = 0; i < 8; i++){
    lc.setRow(0,i,cuatro[i]);
  }
}
void mostrar_441(){     // Mostrar 3 Sets J1 1 Set J2
  for (int i = 0; i < 8; i++){
    lcc.setRow(0,i,cuatroJ1[i]);
  }
}
void mostrar_442(){     // Mostrar 2 Sets J1 2 Sets J2
  for (int i = 0; i < 8; i++){
    lcc.setRow(0,i,cuatroEmp[i]);
  }
}
void mostrar_443(){     // Mostrar 3 Sets J2 1 Set J1
  for (int i = 0; i < 8; i++){
    lcc.setRow(0,i,cuatroJ2[i]);
  }
}
void mostrar_4444(){     // Mostrar 4 J2
  for (int i = 0; i < 8; i++){
    lccc.setRow(0,i,cuatro[i]);
  }
}

void mostrar_5(){     // Mostrar 5 J1
  for (int i = 0; i < 8; i++){
    lc.setRow(0,i,cinco[i]);
  }
}
void mostrar_551(){     // Mostrar 3 Sets J1 2 Sets J2
  for (int i = 0; i < 8; i++){
    lcc.setRow(0,i,cincoJ1[i]);
  }
}
void mostrar_552(){     // Mostrar 3 Sets J2 2 Sets J1
  for (int i = 0; i < 8; i++){
    lcc.setRow(0,i,cincoJ2[i]);
  }
}
void mostrar_5555(){     // Mostrar 5 J2
  for (int i = 0; i < 8; i++){
    lccc.setRow(0,i,cinco[i]);
  }
}

void mostrar_6(){     // Mostrar 6 J1
  for (int i = 0; i < 8; i++){
    lc.setRow(0,i,seis[i]);
  }
}
void mostrar_6666(){     // Mostrar 6 J2
  for (int i = 0; i < 8; i++){
    lccc.setRow(0,i,seis[i]);
  }
}

void mostrar_7(){     // Mostrar 7 J1
  for (int i = 0; i < 8; i++){
    lc.setRow(0,i,siete[i]);
  }
}
void mostrar_7777(){     // Mostrar 7 J2
  for (int i = 0; i < 8; i++){
    lccc.setRow(0,i,siete[i]);
  }
}

void mostrar_8(){     // Mostrar 8 J1
  for (int i = 0; i < 8; i++){
    lc.setRow(0,i,ocho[i]);
  }
}
void mostrar_8888(){     // Mostrar 8 J2
  for (int i = 0; i < 8; i++){
    lccc.setRow(0,i,ocho[i]);
  }
}

void mostrar_9(){     // Mostrar 9 J1
  for (int i = 0; i < 8; i++){
    lc.setRow(0,i,nueve[i]);
  }
}
void mostrar_9999(){     // Mostrar 9 J2
  for (int i = 0; i < 8; i++){
    lccc.setRow(0,i,nueve[i]);
  }  
}

void mostrar_00(){     // Mostrar 10 J1
  for (int i = 0; i < 8; i++){
    lc.setRow(0,i,diez[i]);
  }
}
void mostrar_00000(){     // Mostrar 10 J2
  for (int i = 0; i < 8; i++) {
    lccc.setRow(0,i,diez[i]);
  }  
}

void mostrar_11(){     // Mostrar 11 J1
  for (int i = 0; i < 8; i++){
    lc.setRow(0,i,once[i]);
  }
}
void mostrar_11111(){     // Mostrar 11 J2
  for (int i = 0; i < 8; i++){
    lccc.setRow(0,i,once[i]);
  }  
}

void mostrar_22(){     // Mostrar 12 J1
  for (int i = 0; i < 8; i++){
    lc.setRow(0,i,doce[i]);
  }
}
void mostrar_22222(){     // Mostrar 12 J2
  for (int i = 0; i < 8; i++){
    lccc.setRow(0,i,doce[i]);
  }  
}

void mostrar_33(){     // Mostrar 13 J1
  for (int i = 0; i < 8; i++){
    lc.setRow(0,i,trece[i]);
  }
}
void mostrar_33333(){     // Mostrar 13 J2
  for (int i = 0; i < 8; i++){
    lccc.setRow(0,i,trece[i]);
  }  
}

void mostrar_44(){     // Mostrar 14 J1
  for (int i = 0; i < 8; i++){
    lc.setRow(0,i,catorce[i]);
  }
}
void mostrar_44444(){     // Mostrar 14 J2
  for (int i = 0; i < 8; i++){
    lccc.setRow(0,i,catorce[i]);
  }  
}

void mostrar_55(){     // Mostrar 15 J1
  for (int i = 0; i < 8; i++){
    lc.setRow(0,i,quince[i]);
  }
}
void mostrar_55555(){     // Mostrar 15 J2
  for (int i = 0; i < 8; i++){
    lccc.setRow(0,i,quince[i]);
  }  
}

void mostrar_66(){     // Mostrar 16 J1
  for (int i = 0; i < 8; i++){
    lc.setRow(0,i,dieciseis[i]);
  }
}
void mostrar_66666(){     // Mostrar 16 J2
  for (int i = 0; i < 8; i++){
    lccc.setRow(0,i,dieciseis[i]);
  }  
}

void mostrar_77(){     // Mostrar 17 J1
  for (int i = 0; i < 8; i++){
    lc.setRow(0,i,diecisiete[i]);
  }
}
void mostrar_77777(){     // Mostrar 17 J2
  for (int i = 0; i < 8; i++){
    lccc.setRow(0,i,diecisiete[i]);
  }  
}

void mostrar_88(){     // Mostrar 18 J1
  for (int i = 0; i < 8; i++){
    lc.setRow(0,i,dieciocho[i]);
  }
}
void mostrar_88888(){     // Mostrar 18 J2
  for (int i = 0; i < 8; i++){
    lccc.setRow(0,i,dieciocho[i]);
  }  
}

void mostrar_99(){     // Mostrar 19 J1
  for (int i = 0; i < 8; i++){
    lc.setRow(0,i,diecinueve[i]);
  }
}
void mostrar_99999(){     // Mostrar 19 J2
  for (int i = 0; i < 8; i++){
    lccc.setRow(0,i,diecinueve[i]);
  }  
}



// PINES DE LAS MATRICES PARA JUGADORES Y SETS
int set3 = 2;
int set5 = 3;
int j1 = 4;
int j2 = 5;
int j1r = 0;
int j2r = 13;
int contj1=0;
int contj2=0;
int settJ1=0;
int settJ2=0;
int a=0,b=0,c=0,d=0,e=0,f=0;
int i = 0;

void setup() {
  Serial.begin(9600);
  pinMode(j1,INPUT_PULLUP);
  pinMode(j2,INPUT_PULLUP);
  pinMode(set3,INPUT_PULLUP);
  pinMode(set5,INPUT_PULLUP);
  pinMode(j1r, INPUT_PULLUP);
  pinMode(j2r, INPUT_PULLUP);
  
  lc.shutdown(0,false);     // Enciende matriz
  lc.setIntensity(0,4);     // Brillo de matriz
  lc.clearDisplay(0);     // Matriz vacía
  lcc.shutdown(0,false);
  lcc.setIntensity(0,8);
  lcc.clearDisplay(0);
  lccc.shutdown(0,false);
  lccc.setIntensity(0,4);
  lccc.clearDisplay(0);

  mostrar_0();
  mostrar_000();       
  mostrar_0000();
}

void loop(){
  // ------------- NUEVO --------------------------------------------------------------------------
  if (Serial.available() > 0) {
    char command = Serial.read();
    
    if (command == 'A') {
      contj1++; 
      // Check if Player 1 wins the set (11 points or 2-point lead after 10-10)
      if ((contj1 >= 11 && contj2 <= 9) || (contj1 >= 10 && contj2 >= 10 && contj1 == contj2 + 2)) {
        contj1 = 0;
        contj2 = 0; 
        settJ1++;
        mostrar_0000(); // Reset J2 display
      }
      a = 1; // This triggers your existing "mostrar_X" functions below
    } 
    
    else if (command == 'B') {
      contj2++;
      // Check if Player 2 wins the set
      if ((contj2 >= 11 && contj1 <= 9) || (contj2 >= 10 && contj1 >= 10 && contj2 == contj1 + 2)) {
        contj1 = 0;
        contj2 = 0; 
        settJ2++;
        mostrar_0(); // Reset J1 display
      }
      b = 1; // This triggers your existing "mostrar_X" functions below
    }
  }
  // ---------------------------------------------------------------------------------------------
  
  if(digitalRead(set3)==LOW && c==0){
    Serial.println("Set3 OFF");
    c=1;
  }
  
  if(digitalRead(set3)== HIGH && c==1){
    Serial.println("Set3 ON");
    if(digitalRead(j1)==LOW && a==0){
      Serial.println("Jug1 OFF");
      a=1;
      contj1 += 1;
      if(contj1==11 && contj2<=9){
        contj1=0;
        contj2=0; 
        settJ1 += 1;
        mostrar_0000();
      }
      else if(contj1>= 10 && contj2 >= 10 && contj1==contj2+2){
        contj1=0;
        contj2=0; 
        settJ1 += 1;
        mostrar_0000();
      }
      delay(100);
    } // Botón J1 Apagado

    
    if(digitalRead(j1)== HIGH && a==1){
      Serial.println("Jug1 ON");
      a=0;
      if(contj1==0){
        mostrar_0();
      }
      else if(contj1==1){
        mostrar_1();   
      }
      else if(contj1==2){
        mostrar_2();   
      }
      else if(contj1==3){
        mostrar_3();   
      }
      else if(contj1==4){
        mostrar_4();   
      }
      else if(contj1==5){
        mostrar_5();   
      }
      else if(contj1==6){
        mostrar_6();   
      }
      else if(contj1==7){
        mostrar_7();   
      }
      else if(contj1==8){
        mostrar_8();   
      }
      else if(contj1==9){
        mostrar_9();   
      }
      else if(contj1==10){
        mostrar_00();   
      }
      else if(contj1==11){
        mostrar_11();   
      }
      else if(contj1==12){
        mostrar_22();   
      }
      else if(contj1==13){
        mostrar_33();   
      }
      else if(contj1==14){
        mostrar_44();   
      }
      else if(contj1==15){
        mostrar_55();   
      }
      else if(contj1==16){
        mostrar_66();   
      }
      else if(contj1==17){
        mostrar_77();   
      }
      else if(contj1==18){
        mostrar_88();   
      }
      else if(contj1==19){
        mostrar_99();   
      }

      
      if(settJ1==1 && settJ2==0){
        mostrar_111();
      }
      if(settJ1==1 && settJ2==1){
        mostrar_222();
      }
      if(settJ1==2 && settJ2==0){
        while(i < 25){
          mostrar_10();
          delay(300);
          mostrar_221();
          delay(300);
          i += 1;
        }
        contj1=0; 
        contj2=0;  
        settJ1=0;
        settJ2=0; 
        mostrar_0(); 
        mostrar_000(); 
        mostrar_0000(); 
        a=0;
        b=0;
        i=0;
      }
      if(settJ1==2 && settJ2==1){
        while(i < 25){
          mostrar_10();
          delay(300);
          mostrar_332();
          delay(300);
          i += 1;
        }
        contj1=0; 
        contj2=0;  
        settJ1=0;
        settJ2=0; 
        mostrar_0(); 
        mostrar_000(); 
        mostrar_0000(); 
        a=0;
        b=0;
        i=0;
      }
      if(settJ2==2 && settJ1==1){
        while(i < 25){
          mostrar_10();
          delay(300);
          mostrar_333();
          delay(300);
          i += 1;
        }
        contj1=0; 
        contj2=0;  
        settJ1=0;
        settJ2=0; 
        mostrar_0(); 
        mostrar_000(); 
        mostrar_0000(); 
        a=0;
        b=0;
        i=0;
      }
    } // Botón J1 Encendido

    if(digitalRead(j1r)==LOW && e==0){
      Serial.println("Ju1R OFF");
      e=1;
      contj1 -= 1;
      if(contj1<= 0){
        contj1=0;
        mostrar_0();
      }
      delay(100);
    } // Botón J1 Restar Apagado

    if(digitalRead(j1r)==HIGH && e==1){
      Serial.println("Ju1R ON");
      e=0;
      if(contj1==0){
        mostrar_0();
      }
      else if(contj1==1){
        mostrar_1();   
      }
      else if(contj1==2){
        mostrar_2();   
      }
      else if(contj1==3){
        mostrar_3();   
      }
      else if(contj1==4){
        mostrar_4();   
      }
      else if(contj1==5){
        mostrar_5();   
      }
      else if(contj1==6){
        mostrar_6();   
      }
      else if(contj1==7){
        mostrar_7();   
      }
      else if(contj1==8){
        mostrar_8();   
      }
      else if(contj1==9){
        mostrar_9();   
      }
      else if(contj1==10){
        mostrar_00();   
      }
      else if(contj1==11){
        mostrar_11();   
      }
      else if(contj1==12){
        mostrar_22();   
      }
      else if(contj1==13){
        mostrar_33();   
      }
      else if(contj1==14){
        mostrar_44();   
      }
      else if(contj1==15){
        mostrar_55();   
      }
      else if(contj1==16){
        mostrar_66();   
      }
      else if(contj1==17){
        mostrar_77();   
      }
      else if(contj1==18){
        mostrar_88();   
      }
      else if(contj1==19){
        mostrar_99();   
      }
    } // Botón J1 Restar Encendido
  
    if(digitalRead(j2)==LOW && b==0){
      Serial.println("Jug2 OFF");
      b=1;
      contj2 += 1; 
      if(contj2==11 && contj1<=9){
        contj1=0;
        contj2=0; 
        settJ2 += 1;
        mostrar_0();   
      }
      else if(contj2>= 10 && contj1 >= 10 && contj2==contj1+2){
        contj1=0;
        contj2=0; 
        settJ2 += 1;
        mostrar_0();
      }
      delay(100);
    } // Botón J2 Apagado

    
    if(digitalRead(j2)== HIGH && b==1){
      Serial.println("Jug2 ON");
      b=0;
      if(contj2==0){
        mostrar_0000();   
      }
      else if(contj2==1){
        mostrar_1111();   
      }
      else if(contj2==2){
        mostrar_2222();   
      }
      else if(contj2==3){
        mostrar_3333();   
      }
      else if(contj2==4){
        mostrar_4444();   
      }
      else if(contj2==5){
        mostrar_5555();   
      }
      else if(contj2==6){
        mostrar_6666();   
      }
      else if(contj2==7){
        mostrar_7777();   
      }
      else if(contj2==8){
        mostrar_8888();   
      }
      else if(contj2==9){
        mostrar_9999();   
      }
      else if(contj2==10){
        mostrar_00000();   
      }
      else if(contj2==11){
        mostrar_11111();   
      }
      else if(contj2==12){
        mostrar_22222();   
      }
      else if(contj2==13){
        mostrar_33333();   
      }
      else if(contj2==14){
        mostrar_44444();   
      }
      else if(contj2==15){
        mostrar_55555();   
      }
      else if(contj2==16){
        mostrar_66666();   
      }
      else if(contj2==17){
        mostrar_77777();   
      }
      else if(contj2==18){
        mostrar_88888();   
      }
      else if(contj2==19){
        mostrar_99999();   
      }

    
      if(settJ2==1 && settJ1==0){
        mostrar_112();
      }
      if(settJ2==1 && settJ1==1){
        mostrar_222();
      }
      if(settJ2==2 && settJ1==0){
        while(i < 25){
          mostrar_10();
          delay(300);
          mostrar_223();
          delay(300);
          i += 1;
        }
        contj1=0; 
        contj2=0;  
        settJ1=0;
        settJ2=0; 
        mostrar_0(); 
        mostrar_000(); 
        mostrar_0000(); 
        a=0;
        b=0;
        i=0;
      }
      if(settJ1==2 && settJ2==1){
        while(i < 25){
          mostrar_10();
          delay(300);
          mostrar_332();
          delay(300);
          i += 1;
        }
        contj1=0; 
        contj2=0;  
        settJ1=0;
        settJ2=0; 
        mostrar_0(); 
        mostrar_000(); 
        mostrar_0000(); 
        a=0;
        b=0;
        i=0;
      }
      if(settJ2==2 && settJ1==1){
        while(i < 25){
          mostrar_10();
          delay(300);
          mostrar_333();
          delay(300);
          i += 1;
        }
        contj1=0; 
        contj2=0;  
        settJ1=0;
        settJ2=0; 
        mostrar_0(); 
        mostrar_000(); 
        mostrar_0000(); 
        a=0;
        b=0;
        i=0;
      }
      delay(100);
    } // Botón J2 Encendido

    if(digitalRead(j2r)==LOW && f==0){
      Serial.println("Ju2R OFF");
      f=1;
      contj2 -= 1;
      if(contj2<= 0){
        contj2=0;
        mostrar_0000();
      }
      delay(100);
    } // Botón J2 Restar Apagado

    if(digitalRead(j2r)==HIGH && f==1){
      Serial.println("Ju1R OFF");
      f=0;
      if(contj2==0){
        mostrar_0000();   
      }
      else if(contj2==1){
        mostrar_1111();   
      }
      else if(contj2==2){
        mostrar_2222();   
      }
      else if(contj2==3){
        mostrar_3333();   
      }
      else if(contj2==4){
        mostrar_4444();   
      }
      else if(contj2==5){
        mostrar_5555();   
      }
      else if(contj2==6){
        mostrar_6666();   
      }
      else if(contj2==7){
        mostrar_7777();   
      }
      else if(contj2==8){
        mostrar_8888();   
      }
      else if(contj2==9){
        mostrar_9999();   
      }
      else if(contj2==10){
        mostrar_00000();   
      }
      else if(contj2==11){
        mostrar_11111();   
      }
      else if(contj2==12){
        mostrar_22222();   
      }
      else if(contj2==13){
        mostrar_33333();   
      }
      else if(contj2==14){
        mostrar_44444();   
      }
      else if(contj2==15){
        mostrar_55555();   
      }
      else if(contj2==16){
        mostrar_66666();   
      }
      else if(contj2==17){
        mostrar_77777();   
      }
      else if(contj2==18){
        mostrar_88888();   
      }
      else if(contj2==19){
        mostrar_99999();   
      }
    } // Botón J2 Restar Encendido
  } // Set 3


  if(digitalRead(set5)==LOW && d==0){
    Serial.println("Set5 OFF");
    d=1;
  }
  if(digitalRead(set5)== HIGH && d==1){
    Serial.println("Set5 ON");
    if(digitalRead(j1)==LOW && a==0){
      Serial.println("Jug1 OFF");
      a=1;
      contj1 += 1;
      if(contj1==11 && contj2<=9){
        contj1=0;
        contj2=0; 
        settJ1 += 1;
        mostrar_0000();
      }
      else if(contj1>= 10 && contj2 >= 10 && contj1==contj2+2){
        contj1=0;
        contj2=0; 
        settJ1 += 1;
        mostrar_0000();
      }
      delay(100);
    } // Botón J1 Apagado

    
    if(digitalRead(j1)== HIGH && a==1){
      Serial.println("Jug1 ON");
      a=0;
      if(contj1==0){
        mostrar_0();
      }
      else if(contj1==1){
        mostrar_1();   
      }
      else if(contj1==2){
        mostrar_2();   
      }
      else if(contj1==3){
        mostrar_3();   
      }
      else if(contj1==4){
        mostrar_4();   
      }
      else if(contj1==5){
        mostrar_5();   
      }
      else if(contj1==6){
        mostrar_6();   
      }
      else if(contj1==7){
        mostrar_7();   
      }
      else if(contj1==8){
        mostrar_8();   
      }
      else if(contj1==9){
        mostrar_9();   
      }
      else if(contj1==10){
        mostrar_00();   
      }
      else if(contj1==11){
        mostrar_11();   
      }
      else if(contj1==12){
        mostrar_22();   
      }
      else if(contj1==13){
        mostrar_33();   
      }
      else if(contj1==14){
        mostrar_44();   
      }
      else if(contj1==15){
        mostrar_55();   
      }
      else if(contj1==16){
        mostrar_66();   
      }
      else if(contj1==17){
        mostrar_77();   
      }
      else if(contj1==18){
        mostrar_88();   
      }
      else if(contj1==19){
        mostrar_99();   
      }

      
      if(settJ1==1 && settJ2==0){
      mostrar_111();
      }
      if(settJ1==1 && settJ2==1){
        mostrar_222();
      }
      if(settJ1==2 && settJ2==0){
        mostrar_221();
      }
      if(settJ1==2 && settJ2==1){
        mostrar_332();
      }
      if(settJ1==1 && settJ2==2){
        mostrar_333();
      }
      if(settJ1==2 && settJ2==2){
        mostrar_442();
      }
      if(settJ1==3 && settJ2==0){
        while(i < 25){
          mostrar_10();
          delay(300);
          mostrar_331();
          delay(300);
          i = i+1;
        }
        contj1=0; 
        contj2=0;  
        settJ1=0;
        settJ2=0; 
        mostrar_0(); 
        mostrar_000(); 
        mostrar_0000(); 
        a=0;
        b=0;
        i=0;
      }
      if(settJ1==3 && settJ2==1){
        while(i < 25){
          mostrar_10();
          delay(300);
          mostrar_441();
          delay(300);
          i = i+1;
        }
        contj1=0; 
        contj2=0;  
        settJ1=0;
        settJ2=0;
        mostrar_0(); 
        mostrar_000(); 
        mostrar_0000(); 
        a=0;
        b=0;
        i=0;
      }
      if(settJ1==3 && settJ2==2){
        while(i < 25){
          mostrar_10();
          delay(300);
          mostrar_551();
          delay(300);
          i = i+1;
        }
        contj1=0; 
        contj2=0;  
        settJ1=0;
        settJ2=0;
        mostrar_0(); 
        mostrar_000(); 
        mostrar_0000(); 
        a=0;
        b=0;
        i=0;
      }
    } // Botón J1 Encendido

    if(digitalRead(j1r)==LOW && e==0){
      Serial.println("Ju1R OFF");
      e=1;
      contj1 -= 1;
      if(contj1<= 0){
        contj1=0;
        mostrar_0();
      }
      delay(100);
    } // Botón J1 Restar Apagado

    if(digitalRead(j1r)==HIGH && e==1){
      Serial.println("Ju1R ON");
      e=0;
      if(contj1==0){
        mostrar_0();
      }
      else if(contj1==1){
        mostrar_1();   
      }
      else if(contj1==2){
        mostrar_2();   
      }
      else if(contj1==3){
        mostrar_3();   
      }
      else if(contj1==4){
        mostrar_4();   
      }
      else if(contj1==5){
        mostrar_5();   
      }
      else if(contj1==6){
        mostrar_6();   
      }
      else if(contj1==7){
        mostrar_7();   
      }
      else if(contj1==8){
        mostrar_8();   
      }
      else if(contj1==9){
        mostrar_9();   
      }
      else if(contj1==10){
        mostrar_00();   
      }
      else if(contj1==11){
        mostrar_11();   
      }
      else if(contj1==12){
        mostrar_22();   
      }
      else if(contj1==13){
        mostrar_33();   
      }
      else if(contj1==14){
        mostrar_44();   
      }
      else if(contj1==15){
        mostrar_55();   
      }
      else if(contj1==16){
        mostrar_66();   
      }
      else if(contj1==17){
        mostrar_77();   
      }
      else if(contj1==18){
        mostrar_88();   
      }
      else if(contj1==19){
        mostrar_99();   
      }
    } // Botón J1 Restar Encendido
  
    if(digitalRead(j2)==LOW && b==0){
      Serial.println("Jug2 OFF");
      b=1;
      contj2 += 1; 
      if(contj2==11 && contj1<=9){
        contj1=0;
        contj2=0; 
        settJ2 += 1;
        mostrar_0();   
      }
      else if(contj2>= 10 && contj1 >= 10 && contj2==contj1+2){
        contj1=0;
        contj2=0; 
        settJ2 += 1;
        mostrar_0();
      }
      delay(100);
    } // Botón J2 Apagado

    
    if(digitalRead(j2)== HIGH && b==1){
      Serial.println("Jug2 ON");
      b=0;
      if(contj2==0){
        mostrar_0000();   
      }
      else if(contj2==1){
        mostrar_1111();   
      }
      else if(contj2==2){
        mostrar_2222();   
      }
      else if(contj2==3){
        mostrar_3333();   
      }
      else if(contj2==4){
        mostrar_4444();   
      }
      else if(contj2==5){
        mostrar_5555();   
      }
      else if(contj2==6){
        mostrar_6666();   
      }
      else if(contj2==7){
        mostrar_7777();   
      }
      else if(contj2==8){
        mostrar_8888();   
      }
      else if(contj2==9){
        mostrar_9999();   
      }
      else if(contj2==10){
        mostrar_00000();   
      }
      else if(contj2==11){
        mostrar_11111();   
      }
      else if(contj2==12){
        mostrar_22222();   
      }
      else if(contj2==13){
        mostrar_33333();   
      }
      else if(contj2==14){
        mostrar_44444();   
      }
      else if(contj2==15){
        mostrar_55555();   
      }
      else if(contj2==16){
        mostrar_66666();   
      }
      else if(contj2==17){
        mostrar_77777();   
      }
      else if(contj2==18){
        mostrar_88888();   
      }
      else if(contj2==19){
        mostrar_99999();   
      }

    
      if(settJ2==1 && settJ1==0){
        mostrar_112();
      }
      if(settJ2==1 && settJ1==1){
        mostrar_222();
      }
      if(settJ2==2 && settJ1==0){
        mostrar_223();
      }
      if(settJ2==1 && settJ1==2){
        mostrar_332();
      }
      if(settJ2==2 && settJ1==1){
        mostrar_333();
      }
      if(settJ2==2 && settJ1==2){
        mostrar_442();
      }
      if(settJ2==3 && settJ1==0){
        while(i < 25){
          mostrar_10();
          delay(300);
          mostrar_334();
          delay(300);
          i = i+1;
        }
        contj1=0; 
        contj2=0;  
        settJ1=0;
        settJ2=0; 
        mostrar_0(); 
        mostrar_000(); 
        mostrar_0000(); 
        a=0;
        b=0;
        i=0;
      }
      if(settJ2==3 && settJ1==1){
        while(i < 25){
          mostrar_10();
          delay(300);
          mostrar_443();
          delay(300);
          i = i+1;
        }
        contj1=0; 
        contj2=0;  
        settJ1=0;
        settJ2=0;
        mostrar_0(); 
        mostrar_000(); 
        mostrar_0000(); 
        a=0;
        b=0;
        i=0;
      }
      if(settJ2==3 && settJ1==2){
        while(i < 25){
          mostrar_10();
          delay(300);
          mostrar_552();
          delay(300);
          i = i+1;
        }
        contj1=0; 
        contj2=0;  
        settJ1=0;
        settJ2=0;
        mostrar_0(); 
        mostrar_000(); 
        mostrar_0000(); 
        a=0;
        b=0;
        i=0;
      }
      delay(100);
    } // Botón J2 Encendido

    if(digitalRead(j2r)==LOW && f==0){
      Serial.println("Ju2R OFF");
      f=1;
      contj2 -= 1;
      if(contj2<= 0){
        contj2=0;
        mostrar_0000();
      }
      delay(100);
    } // Botón J2 Restar Apagado

    if(digitalRead(j2r)==HIGH && f==1){
      Serial.println("Ju1R OFF");
      f=0;
      if(contj2==0){
        mostrar_0000();   
      }
      else if(contj2==1){
        mostrar_1111();   
      }
      else if(contj2==2){
        mostrar_2222();   
      }
      else if(contj2==3){
        mostrar_3333();   
      }
      else if(contj2==4){
        mostrar_4444();   
      }
      else if(contj2==5){
        mostrar_5555();   
      }
      else if(contj2==6){
        mostrar_6666();   
      }
      else if(contj2==7){
        mostrar_7777();   
      }
      else if(contj2==8){
        mostrar_8888();   
      }
      else if(contj2==9){
        mostrar_9999();   
      }
      else if(contj2==10){
        mostrar_00000();   
      }
      else if(contj2==11){
        mostrar_11111();   
      }
      else if(contj2==12){
        mostrar_22222();   
      }
      else if(contj2==13){
        mostrar_33333();   
      }
      else if(contj2==14){
        mostrar_44444();   
      }
      else if(contj2==15){
        mostrar_55555();   
      }
      else if(contj2==16){
        mostrar_66666();   
      }
      else if(contj2==17){
        mostrar_77777();   
      }
      else if(contj2==18){
        mostrar_88888();   
      }
      else if(contj2==19){
        mostrar_99999();   
      }
    } // Botón J2 Restar Encendido
  } // Set 5
} // Void Loop
