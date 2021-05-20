const int buttonpin = 6;
const int buzzerpin = 2;
int buttonstate = 0;
void setup() {
  pinMode(buttonpin, INPUT);
  pinMode(buzzerpin, OUTPUT);
}

void loop() {
  buttonstate = digitalRead(buttonpin);
  if (buttonstate == HIGH) {
    //delay(5000);
    digitalWrite(buzzerpin, HIGH);
    delay(50);
    digitalWrite(buzzerpin, LOW);
    delay(50);
    digitalWrite(buzzerpin, HIGH);
    delay(50);
    digitalWrite(buzzerpin, LOW);
  }
}
