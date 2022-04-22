#include <Servo.h>
Servo servo;
int pin1 = 4;
int pin2 = 5;
int pin3 = 6;
int pin4 = 7;
int echo = 9;
int trig = 10;
long jarak, durasi;
int time = 1000;


void setup() {
    servo.attach(11);
    servo.write(90);
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pin3, OUTPUT);
    pinMode(pin4, OUTPUT);
    pinMode(echo, INPUT);
    pinMode(trig, OUTPUT);
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin4, LOW);  
}


void belokKanan() {
  if(jarak >= 20) {
    digitalWrite(pin1, HIGH);
    digitalWrite(pin3, HIGH);
  }
  else if(jarak <= 10) {
    servo.write(180);
    if(jarak >= 10) {
      digitalWrite(pin2, HIGH);
      digitalWrite(pin3, HIGH);
      delay(1000);
      servo.write(90);
      digitalWrite(pin1, HIGH);
      digitalWrite(pin3, HIGH);
    }
    else {
      servo.write(90);
      delay(time);
      servo.write(0);
    }
  }
  if(jarak <= 10) {
    digitalWrite(pin2, HIGH);
    digitalWrite(pin4, HIGH);
    delay(1000);
    servo.write(90);
    digitalWrite(pin1, HIGH);
    digitalWrite(pin3, HIGH);
  }
  else {
    digitalWrite(pin2, HIGH);
    digitalWrite(pin4, HIGH);
    delay(3000);
    digitalWrite(pin1, HIGH);
    digitalWrite(pin3, HIGH);
  }
}
void loop() {
    digitalWrite(trig, HIGH);
    delayMicroseconds(8);
    digitalWrite(trig, LOW);
    delayMicroseconds(8);
    digitalWrite(trig, HIGH);
    delayMicroseconds(8);
    digitalWrite(trig, LOW);

    durasi = pulseIn(echo, HIGH);
    jarak = (durasi / 2) / 29.1; 
}
