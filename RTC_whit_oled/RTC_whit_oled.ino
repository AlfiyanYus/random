#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "RTClib.h"
#include <Wire.h>
RTC_DS1307 rtc;
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     4

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);
  if(!rtc.begin()) {
    Serial.println("RTC tidak tersedia");
    Serial.flush();
    abort();
  }
  if(!rtc.isrunning()){
    Serial.print("RCT tidak berjalan");
  }
//rtc.adjust(DateTime(2021, 10, 10, 12, 18, 00));
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.drawPixel(10, 10, SSD1306_WHITE);
  display.clearDisplay();
}

void loop() {
  DateTime now = rtc.now();
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();

  int waktu = (now.hour() + now.minute());
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.print(now.hour(), DEC);
  display.print(':');
  display.print(now.minute(), DEC);
  display.println();
  display.display();
  delay(1000);
}
