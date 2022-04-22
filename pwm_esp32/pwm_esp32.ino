int led = 16;
int freq = 5000;
int ledPin = 0;
int resolusi = 8;

void setup() {
 ledcSetup(ledPin, freq, resolusi);
 ledcAttachPin(led, ledPin); 
}

void loop() {
  for(int i = 0; i <=255; i++) {
    ledcWrite(ledPin, i);
    delay(15);
  }
  for(int i = 255; i >= 0; i--) {
    ledcWrite(ledPin, i);
    delay(15);
  }

}
