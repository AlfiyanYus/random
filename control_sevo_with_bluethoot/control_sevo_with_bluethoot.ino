#include <Servo.h>
Servo servo1, servo2, servo3, servo4;


void setup() {
  Serial.begin(9600);
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);

}

void loop() {
  if(Serial.available() >=0) {
    unsigned int nilaiBlmJadi = Serial.read();
    unsigned int nilaiMentah  = Serial.read();
    unsigned int nilaiJadi    = (nilaiBlmJadi * 256) + nilaiMentah;

    if(nilaiJadi >= 1000 && nilaiJadi < 1180) {
      int posServo1 = nilaiJadi;
      posServo1 = map(posServo1,1000,1180,0,180);
      servo1.write(posServo1);
      delay(10);
    }

    if(nilaiJadi >= 2000 && nilaiJadi < 2180) {
      int posServo2 = nilaiJadi;
      posServo2 = map(posServo2,2000,2180,0,180);
      servo2.write(posServo2);
      delay(10);
    }

    if(nilaiJadi >= 3000 && nilaiJadi < 3180) {
      int posServo3 = nilaiJadi;
      posServo3 = map(posServo3,3000,3180,0,180);
      servo3.write(posServo3);
      delay(10);
    }

    if(nilaiJadi >= 4000 && nilaiJadi < 4180) {
      int posServo4 = nilaiJadi;
      posServo4 = map(posServo4,4000,4180,0,180);
      servo4.write(posServo4);
      delay(10);
    }
  }

}
