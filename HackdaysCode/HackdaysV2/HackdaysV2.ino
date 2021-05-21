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
*/
#include "ServoWalking.h"

ServoWalking servoWalking(13,12,11,10,9,8,7,6,5,4,3,2,200);


//--------------------------------------------------------------------------------------Setup
void setup() {
 
//ServoWalking.initialize(13,12,11,10,9,8,7,6,5,4,3,2,200);
  

}
//--------------------------------------------------------------------------------------Loop
void loop() {
  
  servoWalking.Walking(90, 0, 45, -45, 5);
  delay(5000);
  servoWalking.AdvancedWalking(74, 0, 45, -45, 90, 5);
  delay(5000);
  servoWalking.Turning(90, 0, 45, -45, "Left", 10);
  delay(5000);
  servoWalking.Turning(90, 0, 45, -45, "Right", 10);
  delay(5000);
}
