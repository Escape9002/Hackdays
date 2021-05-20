/* HACKDAYS 2021
    Gruppe: Ole, Albert, Thilo, Antonio

    Sense of project:
    Walking Spiderbot

    Wiring of Arduino:
    13 ---> Servo
    ...
    2  ---> Servo
    I am not getting triggered....
*/
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

  int Hhigh = 90;
  int Hdown = 0;

  int SForwards = 45;
  int SBackwards = -45;


int nullstellung = 0;
//--------------------------------------------------------------------------------------Setup
void setup() {
  servoA1.attach(13);
  servoA2.attach(12);
  servoA3.attach(11);

  servoB1.attach(10);
  servoB2.attach(9);
  servoB3.attach(8);

  servoGrnA1.attach(7);
  servoGrnA2.attach(6);
  servoGrnA3.attach(5);

  servoGrnB1.attach(4);
  servoGrnB1.attach(3);
  servoGrnB1.attach(2);

}
//--------------------------------------------------------------------------------------Loop
void loop() {
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

    servoA1.write(SForwards); //vorwärts
    servoA1.write(SForwards);
    servoA1.write(SForwards);

    //----------------------------B
    servoB1.write(SBackwards);  //Rückwärts
    servoB1.write(SBackwards);
    servoB1.write(SBackwards);

    //----------------------------A
    servoGrnA1.write(Hdown); //runter
    servoGrnA1.write(Hdown);
    servoGrnA1.write(Hdown);

    //----------------------------B
    servoGrnB1.write(Hhigh); //hoch
    servoGrnB2.write(Hhigh);
    servoGrnB3.write(Hhigh);

    servoB1.write(SForwards);  //vorwärts
    servoB1.write(SForwards);
    servoB1.write(SForwards);

    //----------------------------A
    servoA1.write(SBackwards); //Rückwärts
    servoA1.write(SBackwards);
    servoA1.write(SBackwards);

    //----------------------------B
    servoGrnB1.write(Hdown); //runter
    servoGrnB1.write(Hdown);
    servoGrnB1.write(Hdown);
  }

  ////////////////////////////////////////////////////nullstellung
  Nullstellen(0);
}
//--------------------------------------------------------------------------------------Advanced Walking (bein höhe | nullstellung der höhe| schrittweite Vorwärts| schrittweite Rückwärts| erhebung menge| menge an schritten)
void AdvancedWalking(int Hhigh, int Hdown , int SForwards, int SBackwards, int rise, int steps) {
  //////////////////////////////////////////////in position bringen
  //----------------------------A
  servoGrnA1.write(Hhigh); //hoch
  servoGrnA2.write(Hhigh);
  servoGrnA3.write(Hhigh);

  servoA1.write(SForwards); //vorwärts
  servoA1.write(SForwards);
  servoA1.write(SForwards);

  //----------------------------B
  servoB1.write(SBackwards);  //Rückwärts
  servoB1.write(SBackwards);
  servoB1.write(SBackwards);
  //----------------------------A
  servoGrnA1.write(Hdown); //runter
  servoGrnA1.write(Hdown);
  servoGrnA1.write(Hdown);
  //----------------------------A
  ////////////////////////////////////////////////laufen
  for ( int i = 0; i <= steps; i++) {
    //----------------------------B
    servoGrnB1.write(Hhigh); //hoch
    servoGrnB2.write(Hhigh);
    servoGrnB3.write(Hhigh);
    //----------------------------A
    servoGrnA1.write(rise); //rise
    servoGrnA2.write(rise);
    servoGrnA3.write(rise);

    servoA1.write(SBackwards); //Rückwärts
    servoA1.write(SBackwards);
    servoA1.write(SBackwards);
    //----------------------------B
    servoB1.write(SForwards); //vorwärts
    servoB1.write(SForwards);
    servoB1.write(SForwards);

    servoGrnB1.write(Hdown); //runter
    servoGrnB2.write(Hdown);
    servoGrnB3.write(Hdown);

    //----------------------------------wiederholung Spiegelverkehrt
    //----------------------------A
    servoGrnA1.write(Hhigh); //hoch
    servoGrnA2.write(Hhigh);
    servoGrnA3.write(Hhigh);
    //----------------------------B
    servoGrnB1.write(rise); //rise
    servoGrnB2.write(rise);
    servoGrnB3.write(rise);

    servoB1.write(SBackwards); //Rückwärts
    servoB1.write(SBackwards);
    servoB1.write(SBackwards);
    //----------------------------A
    servoA1.write(SForwards); //vorwärts
    servoA1.write(SForwards);
    servoA1.write(SForwards);

    servoGrnA1.write(Hdown); //runter
    servoGrnA2.write(Hdown);
    servoGrnA3.write(Hdown);
  }
  ////////////////////////////////////////////////////nullstellung
  Nullstellen(0);

}
//--------------------------------------------------------------------------------------Turn (bein höhe | nullstellung der höhe| schrittweite Vorwärts| schrittweite Rückwärts| richtung| menge an schritten)
void Turning(int Hhigh, int Hdown, int SForwards, int SBackwards, String side, int steps) { 

  servoGrnA2.write(Hhigh); //mitte hochfahren --> quadroped
  servoGrnB2.write(Hhigh);
  
  if (side.equals("Left")) {
  for (int i = 0; i <= steps; i++) {
      servoGrnA1.write(Hhigh); //hoch
      servoA1.write(SForwards); //zur seite
      servoGrnA1.write(Hdown); //runter

      servoGrnA3.write(Hhigh); //hoch
      servoA3.write(SForwards); //zur seite
      servoGrnA3.write(Hdown); //runter

      servoGrnB1.write(Hhigh); //hoch
      servoB1.write(SForwards); //zur seite
      servoGrnB1.write(Hdown); //runter

      servoGrnB3.write(Hhigh); //hoch
      servoB3.write(SForwards); //zur seite
      servoGrnB3.write(Hdown); //runter
    }
  } else if (side.equals("Right")) {
  for (int i = 0; i <= steps; i++) {
      servoGrnA1.write(Hhigh); //hoch
      servoA1.write(SBackwards); //zur seite
      servoGrnA1.write(Hdown); //runter

      servoGrnA3.write(Hhigh); //hoch
      servoA3.write(SBackwards); //zur seite
      servoGrnA3.write(Hdown); //runter

      servoGrnB1.write(Hhigh); //hoch
      servoB1.write(SBackwards); //zur seite
      servoGrnB1.write(Hdown); //runter

      servoGrnB3.write(Hhigh); //hoch
      servoB3.write(SBackwards); //zur seite
      servoGrnB3.write(Hdown); //runter
    }
  }
  Nullstellen(0);

}
//--------------------------------------------------------------------------------------Nullstellen
void Nullstellen(int nullstellung) {
  //----------------------------A
  servoGrnA1.write(Hhigh); //hoch
  servoGrnA2.write(Hhigh);
  servoGrnA3.write(Hhigh);

  servoA1.write(nullstellung); //vorwärts
  servoA1.write(nullstellung);
  servoA1.write(nullstellung);

  servoGrnA1.write(Hdown); //runter
  servoGrnA1.write(Hdown);
  servoGrnA1.write(Hdown);

  //----------------------------B
  servoGrnB1.write(Hhigh); //hoch
  servoGrnB2.write(Hhigh);
  servoGrnB3.write(Hhigh);

  servoB1.write(nullstellung);  //vorwärts
  servoB1.write(nullstellung);
  servoB1.write(nullstellung);

  servoGrnB1.write(Hdown); //runter
  servoGrnB1.write(Hdown);
  servoGrnB1.write(Hdown);
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
