#include <Servo.h>
Servo servo, servo2;
int Xpos = A0;
int Ypos = A1;
int pos = 90;
int pos2 = 90;

void setup() {
  Serial.begin(9600);
  servo.attach(9);
  servo2.attach(10);
  servo.write(pos);
  servo2.write(pos2);
}

void loop() {
  int joyY = analogRead(Ypos);  //membaca nilai dari pin analog
  int joyX = analogRead(Xpos);
  //logika putaran ke kanan joystick 1 x
  if(joyX > 750 && pos < 180) {
    pos = pos + 3;
    servo.write(pos);
    delay(20);
  }
  //logika berputar ke kiri joystick 1 x 
  else if(joyX < 250 && pos > 0) {
    pos = pos - 3;
    servo.write(pos);
    delay(20);
  }
  //logika berputar ke kiri joystick 1 y
  if(joyY > 750 && pos2 < 180) {
    pos2 = pos2 + 3;
    servo2.write(pos2);
    delay(20);
  }
  //logika berputar ke kiri joystick 1 y
  else if(joyY < 250 && pos2 > 0) {
    pos2 = pos2 - 3;
    servo2.write(pos2);
    delay(20);
  }
  //membaca nilai joystick
  Serial.print("nilai x= ");
  Serial.println(joyX);
  Serial.print("nilai y= ");
  Serial.println(joyY);
  //delay(1000);
}
