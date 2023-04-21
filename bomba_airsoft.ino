#include <Arduino.h>
#include <TM1637Display.h>
#include <TM1637Keypad.h>
#include <LiquidCrystal.h>

byte tmrMinutos=0, tmrSegundos=0;
#define clkDspTimer 14
#define dioDspTimer 15
TM1637Keypad dspTimer (clkDspTimer, dioDspTimer);

//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//LiquidCrystal lcd(14, 15, 16, 17, 18, 19);

//pines del Arduino
// 0 y 1 reserva para rs232
// 2 al 7 LCD 16x02
// 8 y 9 display LED tm1637
// 10 SIRENA
// 11 y 12 seleccion color display y luces
// 13 BUZER
// 14 al 21 teclado
#define SIRENA  10
#define ledEquipo1  11
#define ledEquipo2  12
#define BUZER 13

bool ms1000=false, tmrRegresiva=false, bmbExplotar=false, verCodigo=false;
byte medioSeg=0;
int tmrCodigo=0;
char psw[4]={'0','0','0','0'}, codPresionado[4]={'0','0','0','0'};
byte tecla;
int tmp_tiempo=0;

// MODOS DE JUEGO
#define modCOUNTER  1
#define modBUSCAR_DESTRUIR  2
#define modASALTO 3
#define modDOMINACION 4

void setup() {

  Serial.begin(9600); //Puerto serie a 9600 bps

  pinMode(BUZER, OUTPUT);
  pinMode(ledEquipo1, OUTPUT);  pinMode(ledEquipo2, OUTPUT);
  pinMode(SIRENA, OUTPUT);
 
  dspTimer.setBrightness(7); // setBrightness(0 a 7, bool on = true)
  
  // set up the LCD's number of columns and rows:
	//lcd.begin(16, 2);

	// Clears the LCD screen
	//lcd.clear();
  
  
}
 
void loop() {
  byte i;

  tecla=dspTimer.leerTeclado();

  

  Serial.println(tecla);
  delay(1000);

}





//Sonido del buzzer en ms
void bip(int demora) {
  digitalWrite(BUZER, HIGH);
  delay(demora);
  digitalWrite(BUZER, LOW);
  delay(demora);
}


// rutina al recibir evento dato serial
void serialEvent() {
  String rxData;

  if (Serial.available()) {
    rxData=Serial.readStringUntil('\n');
    Serial.println(rxData);
    tmrMinutos = rxData.toInt();
    tmrSegundos = 0;
    tmrRegresiva = true;
  }
}

void mostrarTiempo() {
  if (verCodigo == false) {
    dspTimer.showNumberDec(tmrMinutos, true, 2, 0);
    dspTimer.showNumberDec(tmrSegundos, true, 2, 2);

    Serial.print(tmrMinutos);
    Serial.print(":");
    Serial.println(tmrSegundos);
  }
}

void mostrarCodigo() {

}



//  if (ms1000 == true) {
//     if (tmrRegresiva == true) {
//       if (medioSeg == 2) {
//         if (tmrSegundos > 0)
//           tmrSegundos--;
//         else
//           if (tmrMinutos > 0) {
//             tmrSegundos = 59;
//             tmrMinutos--;
//           }
//           else {
//             bmbExplotar = true;
//             tmrRegresiva = false;
//           }
//         medioSeg = 0;
//         mostrarTiempo();
//       }
//     }    

//     if (verCodigo == true) {
//       tmrCodigo++;
//       if (tmrCodigo > 10) {
//         verCodigo = false;
//         for (i=0; i<4; i++)
//           codPresionado[i]='0';
//       }
//     }
    

//     if (tmp_tiempo==10) {
//       digitalWrite(BUZER, ! digitalRead(BUZER));
//       tmp_tiempo=0;
//     }
//     ms1000 = false;

 // Print a message to the LCD.
	//lcd.print(" Hello world!");

	// set the cursor to column 0, line 1
	// (note: line 1 is the second row, since counting begins with 0):
	//lcd.setCursor(0, 1);
	// Print a message to the LCD.
	//lcd.print(" LCD Tutorial");

