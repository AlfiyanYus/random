#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int sensor = A0;
int data;
void setup() {
 Serial.begin(9600);
 pinMode(sensor, INPUT);
 if(!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
  Serial.println (F("SSD1306 allocation failed"));
  for(;;);
 }
 oled.clearDisplay();
}

void loop() {
  data = analogRead(sensor);
  float nilai = (data/1024.0)*5000;
  float nilaiC = nilai/10;
  float nilaiF = (nilaiC*9)/5 + 32;
  Serial.print("SUHU RUANGAN: ");
  Serial.print(nilaiC);
  Serial.println("°C");
  Serial.print("SUHU RUANGAN: ");
  Serial.print(nilaiF);
  Serial.println("°F");
  //Serial.println(nilai);
  //Serial.println(data);
  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setTextColor(WHITE);
  oled.setCursor(2, 8);
  oled.println(nilaiC);
  oled.setCursor(66, 8);
  oled.println("C");
  oled.setCursor(2, 35);
  oled.println(nilaiF);
  oled.setCursor(66, 35);
  oled.println("F");
  oled.display();
  delay(1000);

}
