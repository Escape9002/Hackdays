/*
   Analog 0-4
    TX (1) / RX(0)

    HM-10- Module:
    https://people.ece.cornell.edu/land/courses/ece4760/PIC32/uart/HM10/DSD%20TECH%20HM-10%20datasheet.pdf

    Please do:
    0. Uncomment BLE stuff [ID:2]
    1. Send "AT" [receive "OK" else go for Link]
    2. Set Service. Send "AT+22be0fa4-b99c-11eb-8529-0242ac130003" [receive "OK+Set:22be0fa4-b99c-11eb-8529-0242ac130003", else go for Link] AT+UUID?
    3. Set Characteristic. Send "AT+CHARa1baf394-b99c-11eb-8529-0242ac130003" [receive "OK+Set:a1baf394-b99c-11eb-8529-0242ac130003"] AT+CHAR?
    4. Comment [ID:2]. Uncomment [ID:1] (!multiple lines of crac..code)
    5.Working?? Yeahhaaaaa

*/

#include <SoftwareSerial.h>
SoftwareSerial HM10(A0, A1); // RX = 0, TX = 1

char appData;
String inData = "";

void setup() {
  //------------------HM-10
  Serial.begin(9600);
  Serial.println("HM10 serial started at 9600");
  HM10.begin(9600); // set HM10 serial at 9600 baud rate
}
void loop() {
  HM10.listen();  // listen the HM10 port
  while (HM10.available() > 0) {   // if HM10 sends something then read
    appData = HM10.read();
    inData = String(appData);  // save the data in string format
    Serial.write(appData);
  }

  if (Serial.available()) {           // Read user input if available.
    delay(10);
    HM10.write(Serial.read());
  }
}
