#include <ESP32_Servo.h>
#include <Ps3Controller.h>

Servo servoL;
Servo servoR;
Servo servoB;
Servo servoF;

int posL = 90;
int posR = 90;
int posB = 90;
int posF = 70;

int lx;
int ly;
int rx;
int ry;

void notify() {
  lx = (Ps3.data.analog.stick.lx);
  ly = (Ps3.data.analog.stick.ly);
  rx = (Ps3.data.analog.stick.rx);
  ry = (Ps3.data.analog.stick.ry);
  Serial.print(lx);
  Serial.print(" ");
  Serial.print(ly);
  Serial.print(" ");
  Serial.print(rx);
  Serial.print(" ");
  Serial.println(ry);

  if(lx < -5 && posB < 180) {
    posB++;
    servoB.write(posB);
    delay(10);
  }
  if(lx > 5 && posB > 0) {
    posB--;
    servoB.write(posB);
    delay(10);
  }
  if(ry < -5 && posR < 180) {
    posR++;
    servoR.write(posR);
    delay(10);
  }
  if(ry > 5 && posR > 0) {
    posR--;
    servoR.write(posR);
    delay(10);
  }
  if(rx < -5 && posL < 180) {
    posL++;
    servoL.write(posL);
    delay(10);
  }
  if(rx > 5 && posL > 0) {
    posL--;
    servoL.write(posL);
    delay(10);
  }
  if(abs(Ps3.event.analog_changed.button.l2)) {
    servoF.write(5);
  }
  if(abs(Ps3.event.analog_changed.button.r2)) {
    servoF.write(70);
  }
}

void onConnect() {
  Serial.println("connected.");
}

void setup() {
  Serial.begin(115200);
  Ps3.attach(notify);
  Ps3.attachOnConnect(onConnect);
  Ps3.begin("60:f4:94:59:60:47");
  Serial.println("Ready");
  servoR.attach(22);
  servoL.attach(23);
  servoB.attach(19);
  servoF.attach(18);
  servoR.write(posR);
  servoL.write(posL);
  servoB.write(posB);
  servoF.write(posF);
}

void loop() {
  if(!Ps3.isConnected())
      return;
   delay(2000);   
}
