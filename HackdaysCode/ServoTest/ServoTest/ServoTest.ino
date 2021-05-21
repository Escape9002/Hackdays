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

int Hhigh = 0;
int SBackwards = 0;
int pause = 200;

void setup() {
  //------------------Servo
  servoA1.attach(13);
  servoA2.attach(10);
  servoA3.attach(9);

  servoB1.attach(12);
  servoB2.attach(5);
  servoB3.attach(6);

  servoGrnA1.attach(7);
  servoGrnA2.attach(4);
  servoGrnA3.attach(3);

  servoGrnB1.attach(6);
  servoGrnB1.attach(5);
  servoGrnB1.attach(2);
}

void loop() {
  servoGrnA1.write(Hhigh); //hoch
  servoGrnA2.write(Hhigh);
  servoGrnA3.write(Hhigh);
  delay(pause);
  servoB1.write(SBackwards);  //Rückwärts
  servoB2.write(SBackwards);
  servoB3.write(SBackwards);
  delay(pause);
  servoGrnB1.write(Hhigh); //hoch
  servoGrnB2.write(Hhigh);
  servoGrnB3.write(Hhigh);
  delay(pause);
  servoGrnB1.write(Hhigh); //hoch
  servoGrnB2.write(Hhigh);
  servoGrnB3.write(Hhigh);
  delay(pause);
}
