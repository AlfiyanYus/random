#include <Servo.h>
Servo servo;
int xpin = A0;
int ypin = A1;
int sw = 2;
int led = 3;
int pos = 90;

void setup() {
 Serial.begin(9600);
 pinMode(xpin, INPUT);
 pinMode(ypin, INPUT);
 pinMode(sw, INPUT);
 servo.attach(9);
 servo.write(pos);
}

void loop() {
  int nilaix = analogRead(xpin);
  int nilaiy = analogRead(ypin);
  Serial.print("nilai x= ");
  Serial.println(nilaix);
  Serial.print("nilai y= ");
  Serial.println(nilaiy);
  int nsw = digitalRead(sw);
  bool on = LOW;
  if(nsw == on) {
    Serial.println("button aktif");
  }else {
    Serial.println("button tidak aktif");   
  }
  delay(1000);
}
