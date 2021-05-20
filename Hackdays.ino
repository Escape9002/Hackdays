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

int Hrunter = 0;
int Hhoch = 90;
int winkel = ;

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

void loop() {
  Walking();
}

void Walking(){
  //----------------------------A
  servoGrnA1.write(0); //hoch
  servoGrnA2.write(0);
  servoGrnA3.write(0);

  servoA1.write(45); //vorwärts
  servoA1.write(45);
  servoA1.write(45);

  //----------------------------B
  servoB1.write(-45);  //Rückwärts
  servoB1.write(-45);
  servoB1.write(-45);
  //----------------------------B

  //----------------------------A
  servoGrnA1.write(90); //runter
  servoGrnA1.write(90);
  servoGrnA1.write(90);
  //----------------------------A

  //----------------------------B
  servoGrnB1.write(0); //hoch
  servoGrnB2.write(0);
  servoGrnB3.write(0);

  servoB1.write(45);  //vorwärts
  servoB1.write(45);
  servoB1.write(45);
  //----------------------------B

  //----------------------------A
  servoA1.write(-45); //Rückwärts
  servoA1.write(-45);
  servoA1.write(-45);
  //----------------------------A

  servoGrnB1.write(90); //runter
  servoGrnB1.write(90);
  servoGrnB1.write(90);
  
}

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
