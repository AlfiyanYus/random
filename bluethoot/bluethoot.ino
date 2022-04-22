#include <Servo.h>
Servo servo;

void setup() {
  servo.attach(9);
  Serial.begin(9600);
  servo.write(90);
}

void loop() {
 if(Serial.available() >0) {
  char data = Serial.read();
  switch(data) {
    case '0':
      servo.write(30);
      delay(500);
      servo.write(90);
    break;
    case '1':
      servo.write(160);
      delay(500);
      servo.write(90);
    break;
    default:
    break;
  }
 }
}
