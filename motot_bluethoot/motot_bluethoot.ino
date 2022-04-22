//#include <SoftwareSerial.h>
//SoftwareSerial mySerial(10, 11);
char data; 
int pin1 = 2;
int pin2 = 3;
int pin3 = 4;
int pin4 = 5;
//int pinNa= 9;
const int led = 13;
void setup() {
  Serial.begin(9600);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  //pinMode(pinNa,OUTPUT);
}

void loop() {
  if(Serial.available()) {
    data = Serial.read();
    Serial.println(data);
  }
    /*int nilaiA = Serial.read();
    //int nilaiB = mySerial.read();
    //int nilaiJ = (nilaiA * 255) + nilaiB;
    switch (data) {
      case '1':
        digitalWrite(pinNa, 155);
        break;
      case '2':
        digitalWrite(pinNa, 165);
        break;
      case '3':
        digitalWrite(pinNa, 175);
        break;
      case '4':
        digitalWrite(pinNa, 185);
        break;
      case '5':
        digitalWrite(pinNa, 195);
        break;
      default:
        break;
    }

    switch (data) {
      case '6':
        digitalWrite(pinNa, 205);
        break;
      case '7':
        digitalWrite(pinNa, 215);
        break;
      case '8':
        digitalWrite(pinNa, 225);
        break;
      case '9':
        digitalWrite(pinNa, 245);
        break;
      case 'q':
        digitalWrite(pinNa, 255);
        break;
      default:
        break;
    }*/

    
    if(data == 'F') {
      //MAJU
      digitalWrite(pin1, HIGH);
      digitalWrite(pin3, HIGH);
    }
    else if(data == 'B') {
      //MUNDUR
      digitalWrite(pin2, HIGH);
      digitalWrite(pin4, HIGH);
    }
    else if(data == 'L') {
      //PUTER KIRI
      digitalWrite(pin3, HIGH);
    }
    else if(data == 'R') {
      //PUTER KANAN
      digitalWrite(pin1, HIGH);
    }
    else if(data == 'S') {
      //STOP
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
    }
    else if(data == 'W') {
      digitalWrite(led, HIGH);
    }
    else if(data == 'w') {
      digitalWrite(led, LOW);
    }
    delay(500);    
}   
