#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 rtc;
//#include <TM1637Display.h> //HAPUS TANDA KOMENTAR JIKA INGIN MENGUNAKAN 7 SEGMEN
//#define CLK 2              // YANG BERFORMAT (display)
//#define DIO 3              // 7 segmen meggunakan TM1637, 4 PIN
//TM1637Display display = TM1637Display(CLK, DIO);
#include <Servo.h>
Servo myservo;
int pos = 0;

void setup () {
  Serial.begin(57600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // Hapus tanda komentar di bawah untuk set waktu, dan beri komentar kembali untuk save waktu
    // January 21, 2014 at 3am you would call:
    //rtc.adjust(DateTime(2021, 10, 4, 22, 44, 0));
  }
  myservo.attach(9); // mendefisinikan servo pada pin 9
  myservo.write(0);  // memprintahkan servo umtuk 0 derajar
  //display.setBrightness(5);
  //display.clear();
}

void loop () {
  DateTime now = rtc.now();
  Serial.print(now.hour());
  Serial.print(':');
  Serial.println(now.minute());
  //int displaytime = (now.hour() * 100) + now.minute();
  //display.showNumberDecEx(displaytime, 0b11100000, true);
  if(now.hour() == 7 && now.minute()== 0 && now.second() ==0) {
    for(pos = 0; pos <= 80; pos += 1) {
      myservo.write(pos);
      delay(5);
    }
    for(pos = 80; pos >= 0; pos -= 1) {
      myservo.write(pos);
      delay(5);
    }
  }
  if(now.hour() == 16 && now.minute()== 0 && now.second() ==0) {
    for(pos = 0; pos <= 80; pos += 1) {
      myservo.write(pos);
      delay(5);
    }
    for(pos = 80; pos >= 0; pos -= 1) {
      myservo.write(pos);
      delay(5);
    }
  }
  delay(1000);
}
