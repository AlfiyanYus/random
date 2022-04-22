

int led[] = {2, 3, 4, 5, 6, 7};
int pinLed = 6;

void setup() {
  for(int i = 0; i < pinLed; i++) 
    pinMode(led[i], OUTPUT);
  }
}

void loop() {
 for(int i = 0; i < pinLed; i++) {
  digitalWrite(led[i], HIGH);
  delay(1000);
  digitalWrite(led[i], LOW);
 }
 for(int i = pinLed -1; i >= pinLed; i--) {
  digitalWrite(led[i], HIGH);
  delay(1000);
  digitalWrite(led[i], LOW);
 }

}
