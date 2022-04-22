#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;
char dayOfTheWeek[7][12] = {"Sunday", "Monday", "Yuesday", "Wedsneday", "Tursday", "Friday", "Saturday"};

void setup() {
  Serial.begin(9600);
  delay(3000);
  if(!rtc.begin()) {
    Serial.println("tidak bisa menemukan RTC");
    while(1);
  }
  if(!rtc.isrunning()) {
    Serial.println("RCT perlu di reset, set waktu kembali");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    //rtc.adjust(DateTime(2021, 9, 2, 15, 28, 0));
  }
}

void loop() {
  DateTime now = rtc.now();

  Serial.println("tanggal dan waktu saat ini");
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print("(");
  Serial.print(dayOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(")");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();

  /*Serial.println("Unix Time:  ");
  Serial.print("elapsed");
  Serial.print(now.unixtime());
  Serial.print("second/");
  Serial.print(now.unixtime()/86400L);
  Serial.println("day since 1/1/1970");*/

  Serial.println();
  delay(1000);
 
}
