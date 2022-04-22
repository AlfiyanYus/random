int pin1 = 2;
int pin2 = 3;
int pin3 = 4;
int pin4 = 5;
int enA = 8;
int enB = 9;

void setup() {
    Serial.begin(9600);
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pin3, OUTPUT);
    pinMode(pin4, OUTPUT);
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    
    
}

void loop() {
    directionControl();
    motorMaju();
    motorMundur();
    motorKanan();
    motorKiri();
    motorStop();
    if(Serial.available()) {
       char data = Serial.read();
        switch(data) {
            case '10':
              motorMaju();
            break;
            case '20':
              motorMundur();
            break;
            case '30':
              motorKanan();
            break;
            case '40':
              motorKiri();
             break;
            case '50':
              motorStop();
            default:
            break;
            
        }
    }

}
void directionControl() {
	// Set motors to maximum speed
	// For PWM maximum possible values are 0 to 255
  	analogWrite(enA, 255);
   	analogWrite(enB, 255);
}

void motorMaju() {
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin4, LOW);
}
void motorMundur() {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, HIGH);
}
void motorKanan() {
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW);
}
void motorKiri() {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin4, LOW);
}
void motorStop() {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW);
}
