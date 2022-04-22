int pin1 = 4;
int pin2 = 5;
int pin3 = 6;
int pin4 = 7;
int enA = 8;
int enB = 9;

void setup() {
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pin3, OUTPUT);
    pinMode(pin4, OUTPUT);
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);

}

void loop() {
    analogWrite(enA, 255);
    analogWrite(enB, 255);
    
    digitalWrite(pin1, HIGH);
      digitalWrite(pin2, LOW);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin4, LOW);
    /*delay(5000);

    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, HIGH);
    delay(5000);

    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW);
    delay(5000);

    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin4, LOW);
    delay(5000);*/
}
