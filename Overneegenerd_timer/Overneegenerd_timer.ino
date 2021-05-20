/*
   Over engeneered timer!!!!

   Button: D2
   Buzzer: D3
   Rotary Angle: A0
   LCD : I2C
*/
#define Poti A0

int multiplikator = 10;

#define Buzzer 2
#define buzzes 3
#define interruptPin 3

volatile boolean btnStatus = false;

long timer;
long timerset;
int wait = 5000;
int timerdif = 0;
//-----------------------
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 105;
const int colorG = 75;
const int colorB = 105;
//-----------------------
//----------------------------------------------SETUP
void setup() {
  //-----------------------LCD
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  lcd.setCursor(0, 1);
  lcd.print("Loading...");
  //-----------------------LCD

  Serial.begin(9600);

  pinMode(Buzzer, OUTPUT);
  pinMode(Poti, INPUT);

  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), Btn, HIGH);

  //delay(1000);
  lcd.clear();
}
//----------------------------------------------SETUP
//----------------------------------------------LOOP
void loop() {
  timer = millis();
  debug();

  wait = analogRead(Poti)* multiplikator;
  //-----------------------button
  if (timer > timerset && btnStatus) {
    for (int i = 0; i <= buzzes; i++) {
      digitalWrite(Buzzer, HIGH);
      delay(100);
      digitalWrite(Buzzer, LOW);
      delay(100);
    }
    btnStatus = false;
  } else {
    digitalWrite(Buzzer, LOW);
  }
  //-----------------------button
  //-----------------------lcd output
  timerdif = clamp(0, wait, (timerset - timer));

  //lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Time: " + String((timerdif + 999) / 1000));
  lcd.setCursor(0, 1);
  lcd.print("LOL: " + String((wait/1000)));
  //-----------------------lcd output
}
//----------------------------------------------LOOP
//----------------------------------------------Interrupt function
void Btn() {
  //lcd.clear();
  btnStatus = true;
  timerset = timer + wait;
}
//----------------------------------------------Interrupt function
//----------------------------------------------debug
void debug() {
  String info = String(btnStatus) + " | " + String(timerdif);
  Serial.println(info);
}
//----------------------------------------------debug
//----------------------------------------------clamp   //sets value to own min/max
int clamp(int min, int max, int var) {

  if (var < min) {
    var = min;
  } else if (var > max) {
    var = max;
  }
  return var;
}
//----------------------------------------------clamp
