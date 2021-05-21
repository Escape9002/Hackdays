#include "Arduino.h"
#include "ServoWalking.h"

ServoWalking::ServoWalking(int pin_2, int pin_3, int pin_4, int pin_5, int pin_6, int pin_7, int pin_8, int pin_9, int pin_10 , int pin_11, int pin_12, int pin_13, int _pause) {

  //------------------Servo
  servoA1.attach(pin_2);
  servoA2.attach(pin_3);
  servoA3.attach(pin_4);

  servoB1.attach(pin_5);
  servoB2.attach(pin_6);
  servoB3.attach(pin_7);

  servoGrnA1.attach(pin_8);
  servoGrnA2.attach(pin_9);
  servoGrnA3.attach(pin_10);

  servoGrnB1.attach(pin_11);
  servoGrnB1.attach(pin_12);
  servoGrnB1.attach(pin_13);

  pause = _pause;

}

ServoWalking::Walking(int Hhigh, int Hdown , int SForwards, int SBackwards, int steps) {
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
    servoB2.write(SBackwards);
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
    servoGrnB3.write(Hhigh);
    delay(pause);
    servoB1.write(SForwards);  //vorwärts
    servoB2.write(SForwards);
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
    servoGrnB3.write(Hdown);
    delay(pause);
  }

  ////////////////////////////////////////////////////nullstellung
  Nullstellen(90, 0, 45, -45, 0);
}
}

//--------------------------------------------------------------------------------------Advanced Walking (bein höhe | nullstellung der höhe| schrittweite Vorwärts| schrittweite Rückwärts| erhebung menge| menge an schritten)
ServoWalking::AdvancedWalking(int Hhigh, int Hdown , int SForwards, int SBackwards, int rise, int steps) {
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
  servoB2.write(SBackwards);
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
    servoGrnB3.write(Hhigh);
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
    servoB2.write(SForwards);
    servoB3.write(SForwards);
    delay(pause);
    servoGrnB1.write(Hdown); //runter
    servoGrnB2.write(Hdown);
    servoGrnB3.write(Hdown);
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
    servoGrnB3.write(rise);
    delay(pause);
    servoB1.write(SBackwards); //Rückwärts
    servoB2.write(SBackwards);
    servoB3.write(SBackwards);
    delay(pause);
    servoGrnB1.write(Hdown); //rise
    servoGrnB2.write(Hdown);
    servoGrnB3.write(Hdown);
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
ServoWalking::Turning(int Hhigh, int Hdown, int SForwards, int SBackwards, String side, int steps) {

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
      servoGrnB3.write(Hhigh); //hoch
      servoB3.write(SForwards); //zur seite
      servoGrnB3.write(Hdown); //runter
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
      servoGrnB3.write(Hhigh); //hoch
      servoB3.write(SBackwards); //zur seite
      servoGrnB3.write(Hdown); //runter
      delay(pause);
    }
  }
  Nullstellen(90, 0, 45, -45, 0);

}
//--------------------------------------------------------------------------------------Nullstellen (bein höhe | nullstellung der höhe| schrittweite Vorwärts| schrittweite Rückwärts| nullstellung)
ServoWalking::Nullstellen(int Hhigh, int Hdown, int SForwards, int SBackwards, int nullstellung) {
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
  servoGrnB3.write(Hhigh);
  delay(pause);
  servoB1.write(nullstellung);  //vorwärts
  servoB2.write(nullstellung);
  servoB3.write(nullstellung);
  delay(pause);
  servoGrnB1.write(Hdown); //runter
  servoGrnB2.write(Hdown);
  servoGrnB3.write(Hdown);
  delay(pause);
}
