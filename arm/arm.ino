#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
int data1;
int data2;
int data3;
int data4;

int pot1 = A0;
int pot2 = A1;
int pot3 = A2;
int pot4 = A3;

  
void setup() {
  Serial.begin(9600);
  servo1.attach(5);
  servo2.attach(6);
  servo3.attach(9);
  servo4.attach(10);
  pinMode(pot1, INPUT);
  pinMode(pot2, INPUT);
  pinMode(pot3, INPUT);
  pinMode(pot4, INPUT);

}

void loop() {
  data1 = analogRead(pot1);
  data1 = map(data1,0,1023,0,180);
  servo1.write(data1);
  Serial.println(data1);

  data2 = analogRead(pot2);
  data2 = map(data2,0,1023,0,180);
  servo1.write(data2);

  data3 = analogRead(pot3);
  data3 = map(data3,0,1023,0,180);
  servo1.write(data3);

  data4 = analogRead(pot4);
  data4 = map(data4,0,1023,0,180);
  servo1.write(data4);

  delay(5);
  
}
