/* HACKDAYS 2021
    Gruppe: Ole, Albert, Thilo, Antonio

    Sense of project:
    Walking Spiderbot

    Wiring of Arduino:
    13 ---> Servo
    ...
    2  ---> Servo
    Free:
    I2C
    Analog 0-4
    TX (1) / RX(0)

    HM-10- Module:
    https://people.ece.cornell.edu/land/courses/ece4760/PIC32/uart/HM10/DSD%20TECH%20HM-10%20datasheet.pdf

    Please do:
    0. Uncomment BLE stuff [ID:2]
    1. Send "AT" [receive "OK" else go for Link]
    2. Set Service. Send "AT+22be0fa4-b99c-11eb-8529-0242ac130003" [receive "OK+Set:22be0fa4-b99c-11eb-8529-0242ac130003", else go for Link]
    3. Set Characteristic. Send "AT+CHARa1baf394-b99c-11eb-8529-0242ac130003" [receive "OK+Set:a1baf394-b99c-11eb-8529-0242ac130003"]
    4. Comment [ID:2]. Uncomment [ID:1] (!multiple lines of crac..code)
    5.Working?? Yeahhaaaaa

*/
//----------------------------------BLE
#include <SoftwareSerial.h>
SoftwareSerial HM10(A0, A1); // RX = 0, TX = 1

char appData;
String inData = "";
//----------------------------------Servo
#include <Servo.h>

Servo servoA1;
Servo servoA2;
Servo servoA3;

Servo servoB1;
Servo servoB2;
Servo servoB3;

Servo servoGrnA1;
Servo servoGrnA2;
Servo servoGrnA3;

Servo servoGrnB1;
Servo servoGrnB2;
Servo servoGrnB3;
/*
  int Hhigh = 90;
  int Hdown = 0;

  int SForwards = 45;
  int SBackwards = -45;
*/

int nullstellung = 0;
int pause = 5;

int Offset11 = ;
int Offset8 = ;

//--------------------------------------------------------------------------------------Setup
void setup() {
  //------------------HM-10
  Serial.begin(9600);
  Serial.println("HM10 serial started at 9600");
  HM10.begin(9600); // set HM10 serial at 9600 baud rate

  //------------------Servo
  servoA1.attach(13);
  servoA2.attach(10);
  servoA3.attach(9);

  servoB1.attach(12);
  servoB2.attach(11);
  servoB3.attach(8);

  servoGrnA1.attach(7);
  servoGrnA2.attach(4);
  servoGrnA3.attach(3);

  servoGrnB1.attach(6);
  servoGrnB1.attach(5);
  servoGrnB1.attach(2);

}
//--------------------------------------------------------------------------------------Loop
void loop() {
  //------------------HM-10
  /*  //BLE-Communication (ID:1)
    HM10.listen();  // listen the HM10 port
    while (HM10.available() > 0) {   // if HM10 sends something then read
    appData = HM10.read();
    inData = String(appData);  // save the data in string format
    Serial.write(appData);
    }
  */

  //AT-Command debugging (enable if debugging, only debug when no BLe-Connection) (ID:2)
  /*
    if (Serial.available()) {           // Read user input if available.
    delay(10);
    HM10.write(Serial.read());
    }
  */

  /* //FernbedienungsCode falls BLE funktioniert (ID:1)
    if (inData.equals("W")) {
    AdvancedWalking(74, 0, 45, -45, 90, 1);
    } else if (inData.equals("S")) {
    AdvancedWalking(74, 0, -45, 45, 90, 1); //not sure if working, just changed the 45 to -45 and vise versa
    } else if (inData.equals("A")) {
    Turning(90, 0, 45, -45, "Left", 1);
    } else if (inData.equals("D")) {
    Turning(90, 0, 45, -45, "Right", 1);
    }
  */
  //------------------ServoZeugs (run for function testing!)
  Walking(90, 0, 45, -45, 5);
  delay(5000);
  AdvancedWalking(74, 0, 45, -45, 90, 5);
  delay(5000);
  Turning(90, 0, 45, -45, "Left", 10);
  delay(5000);
  Turning(90, 0, 45, -45, "Right", 10);
  delay(5000);
}
//--------------------------------------------------------------------------------------Walking (bein höhe | nullstellung der höhe| schrittweite Vorwärts| schrittweite Rückwärts| menge an schritten)
void Walking(int Hhigh, int Hdown , int SForwards, int SBackwards, int steps) {
  ////////////////////////////////////////////////////laufen
  for ( int i = 0; i <= steps; i++) {

    //----------------------------A
    servoGrnA1.write(Hhigh); //hoch
    servoGrnA2.write(Hhigh);
    servoGrnA3.write(Hhigh);
    delay(pause);
    servoA1.write(SForwards); //vorwärts
    servoA2.write(SForwards);
    servoA3.write(SForwards);
    delay(pause);
    //----------------------------B
    servoB1.write(SBackwards);  //Rückwärts
    servoB2.write(SBackwards + Offset11);
    servoB3.write(SBackwards);
    delay(pause);
    //----------------------------A
    servoGrnA1.write(Hdown); //runter
    servoGrnA2.write(Hdown);
    servoGrnA3.write(Hdown);
    delay(pause);
    //----------------------------B
    servoGrnB1.write(Hhigh); //hoch
    servoGrnB2.write(Hhigh);
    servoGrnB3.write(Hhigh + Offset8);
    delay(pause);
    servoB1.write(SForwards);  //vorwärts
    servoB2.write(SForwards + Offset11);
    servoB3.write(SForwards);
    delay(pause);
    //----------------------------A
    servoA1.write(SBackwards); //Rückwärts
    servoA2.write(SBackwards);
    servoA3.write(SBackwards);
    delay(pause);
    //----------------------------B
    servoGrnB1.write(Hdown); //runter
    servoGrnB2.write(Hdown);
    servoGrnB3.write(Hdown + Offset8);
    delay(pause);
  }

  ////////////////////////////////////////////////////nullstellung
  Nullstellen(90, 0, 45, -45, 0);
}
//--------------------------------------------------------------------------------------Advanced Walking (bein höhe | nullstellung der höhe| schrittweite Vorwärts| schrittweite Rückwärts| erhebung menge| menge an schritten)
void AdvancedWalking(int Hhigh, int Hdown , int SForwards, int SBackwards, int rise, int steps) {
  //////////////////////////////////////////////in position bringen
  //----------------------------A
  servoGrnA1.write(Hhigh); //hoch
  servoGrnA2.write(Hhigh);
  servoGrnA3.write(Hhigh);
  delay(pause);
  servoA1.write(SForwards); //vorwärts
  servoA2.write(SForwards);
  servoA3.write(SForwards);
  delay(pause);
  //----------------------------B
  servoB1.write(SBackwards);  //Rückwärts
  servoB2.write(SBackwards + Offset11);
  servoB3.write(SBackwards);
  delay(pause);
  //----------------------------A
  servoGrnA1.write(Hdown); //runter
  servoGrnA2.write(Hdown);
  servoGrnA3.write(Hdown);
  delay(pause);
  //----------------------------A
  ////////////////////////////////////////////////laufen
  for ( int i = 0; i <= steps; i++) {
    //----------------------------B
    servoGrnB1.write(Hhigh); //hoch
    servoGrnB2.write(Hhigh);
    servoGrnB3.write(Hhigh + Offset8);
    delay(pause);
    //----------------------------A
    servoGrnA1.write(rise); //rise
    servoGrnA2.write(rise);
    servoGrnA3.write(rise);
    delay(pause);
    servoA1.write(SBackwards); //Rückwärts
    servoA2.write(SBackwards);
    servoA3.write(SBackwards);
    delay(pause);
    servoGrnA1.write(Hdown); //rise
    servoGrnA2.write(Hdown);
    servoGrnA3.write(Hdown);
    delay(pause);
    //----------------------------B
    servoB1.write(SForwards); //vorwärts
    servoB2.write(SForwards + Offset11);
    servoB3.write(SForwards);
    delay(pause);
    servoGrnB1.write(Hdown); //runter
    servoGrnB2.write(Hdown);
    servoGrnB3.write(Hdown + Offset8);
    delay(pause);
    //----------------------------------wiederholung Spiegelverkehrt
    //----------------------------A
    servoGrnA1.write(Hhigh); //hoch
    servoGrnA2.write(Hhigh);
    servoGrnA3.write(Hhigh);
    delay(pause);
    //----------------------------B
    servoGrnB1.write(rise); //rise
    servoGrnB2.write(rise);
    servoGrnB3.write(rise + Offset8);
    delay(pause);
    servoB1.write(SBackwards); //Rückwärts
    servoB2.write(SBackwards + Offset11);
    servoB3.write(SBackwards);
    delay(pause);
    servoGrnB1.write(Hdown); //rise
    servoGrnB2.write(Hdown);
    servoGrnB3.write(Hdown + Offset8);
    delay(pause);
    //----------------------------A
    servoA1.write(SForwards); //vorwärts
    servoA2.write(SForwards);
    servoA2.write(SForwards);
    delay(pause);
    servoGrnA1.write(Hdown); //runter
    servoGrnA2.write(Hdown);
    servoGrnA3.write(Hdown);
    delay(pause);
  }
  ////////////////////////////////////////////////////nullstellung
  Nullstellen(90, 0, 45, -45, 0);

}
//--------------------------------------------------------------------------------------Turn (bein höhe | nullstellung der höhe| schrittweite Vorwärts| schrittweite Rückwärts| richtung| menge an schritten)
void Turning(int Hhigh, int Hdown, int SForwards, int SBackwards, String side, int steps) {

  servoGrnA2.write(Hhigh); //mitte hochfahren --> quadroped
  servoGrnB2.write(Hhigh);
  delay(pause);

  if (side.equals("Left")) {
    for (int i = 0; i <= steps; i++) {
      servoGrnA1.write(Hhigh); //hoch
      servoA1.write(SForwards); //zur seite
      servoGrnA1.write(Hdown); //runter
      delay(pause);
      servoGrnA3.write(Hhigh); //hoch
      servoA3.write(SForwards); //zur seite
      servoGrnA3.write(Hdown); //runter
      delay(pause);
      servoGrnB1.write(Hhigh); //hoch
      servoB1.write(SForwards); //zur seite
      servoGrnB1.write(Hdown); //runter
      delay(pause);
      servoGrnB3.write(Hhigh + Offset8); //hoch
      servoB3.write(SForwards + Offset8); //zur seite
      servoGrnB3.write(Hdown + Offset8); //runter
      delay(pause);
    }
  } else if (side.equals("Right")) {
    for (int i = 0; i <= steps; i++) {
      servoGrnA1.write(Hhigh); //hoch
      servoA1.write(SBackwards); //zur seite
      servoGrnA1.write(Hdown); //runter
      delay(pause);
      servoGrnA3.write(Hhigh); //hoch
      servoA3.write(SBackwards); //zur seite
      servoGrnA3.write(Hdown); //runter
      delay(pause);
      servoGrnB1.write(Hhigh); //hoch
      servoB1.write(SBackwards); //zur seite
      servoGrnB1.write(Hdown); //runter
      delay(pause);
      servoGrnB3.write(Hhigh + Offset8); //hoch
      servoB3.write(SBackwards + Offset8); //zur seite
      servoGrnB3.write(Hdown + Offset8); //runter
      delay(pause);
    }
  }
  Nullstellen(90, 0, 45, -45, 0);

}
//--------------------------------------------------------------------------------------Nullstellen (bein höhe | nullstellung der höhe| schrittweite Vorwärts| schrittweite Rückwärts| nullstellung)
void Nullstellen(int Hhigh, int Hdown, int SForwards, int SBackwards, int nullstellung) {
  //----------------------------A
  servoGrnA1.write(Hhigh); //hoch
  servoGrnA2.write(Hhigh);
  servoGrnA3.write(Hhigh);
  delay(pause);
  servoA1.write(nullstellung); //vorwärts
  servoA2.write(nullstellung);
  servoA3.write(nullstellung);
  delay(pause);
  servoGrnA1.write(Hdown); //runter
  servoGrnA2.write(Hdown);
  servoGrnA3.write(Hdown);
  delay(pause);
  //----------------------------B
  servoGrnB1.write(Hhigh); //hoch
  servoGrnB2.write(Hhigh);
  servoGrnB3.write(Hhigh + Offset8);
  delay(pause);
  servoB1.write(nullstellung);  //vorwärts
  servoB2.write(nullstellung + Offset11);
  servoB3.write(nullstellung);
  delay(pause);
  servoGrnB1.write(Hdown); //runter
  servoGrnB2.write(Hdown);
  servoGrnB3.write(Hdown + Offset8);
  delay(pause);
}
//--------------------------------------------------------Garbage
/*
  //--------------------------------------Vorwärts
  void GroupAForward() {
  servoGrnA1.write(0); //hoch
  servoGrnA2.write(0);
  servoGrnA3.write(0);

  servoA1.write(45); //vorwärts
  servoA1.write(45);
  servoA1.write(45);

  servoGrnA1.write(90); //runter
  servoGrnA1.write(90);
  servoGrnA1.write(90);
  }

  void GroupBForward() {
  servoGrnB1.write(0); //hoch
  servoGrnB2.write(0);
  servoGrnB3.write(0);

  servoB1.write(45);  //vorwärts
  servoB1.write(45);
  servoB1.write(45);

  servoGrnB1.write(90); //runter
  servoGrnB1.write(90);
  servoGrnB1.write(90);
  }
  //--------------------------------------Vorwärts
  //--------------------------------------Rückwärts
  void GroupABackwards() {
  servoGrnA1.write(0); //hoch
  servoGrnA2.write(0);
  servoGrnA3.write(0);

  servoA1.write(-45); //Rückwärts
  servoA1.write(-45);
  servoA1.write(-45);

  servoGrnA1.write(90); //runter
  servoGrnA1.write(90);
  servoGrnA1.write(90);
  }

  void GroupBBackwards() {
  servoGrnB1.write(0); //hoch
  servoGrnB2.write(0);
  servoGrnB3.write(0);

  servoB1.write(-45);  //Rückwärts
  servoB1.write(-45);
  servoB1.write(-45);

  servoGrnB1.write(90); //runter
  servoGrnB1.write(90);
  servoGrnB1.write(90);
  }
  //--------------------------------------Rückwärts
*/
