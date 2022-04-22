#include <Arduino.h>
#include <CTBot.h>
#include <SPI.h>
#include <Wire.h>
#include "RTClib.h"

#include "CTBot.h"
#include <Servo.h>
#define led D4

Servo servo;
CTBot teBot;
int pos = 0;

const char* ssid = "Alfyan_yu";
const char* pass = "what are you say";
const char* token = "1534144953:AAGBCRs_yEIIj37YDZ5CU-3st58n11IGKPI";

unsigned long curentTime;
unsigned long previousTime = 0;
const int timeoutTime = 2000;


RTC_DS1307 rtc;
//#include <TM1637Display.h> //HAPUS TANDA KOMENTAR JIKA INGIN MENGUNAKAN 7 SEGMEN
//#define CLK 2              // YANG BERFORMAT (display)
//#define DIO 3              // 7 segmen meggunakan TM1637, 4 PIN
//TM1637Display display = TM1637Display(CLK, DIO);

void setup () {
  Serial.begin(115200);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // Hapus tanda komentar di bawah untuk set waktu, dan beri komentar kembali untuk save waktu
    // January 21, 2014 at 3am:
    //rtc.adjust(DateTime(2022, 03, 22, 23, 23, 0));
  }
  //display.setBrightness(5);
  //display.clear();


  Serial.println("Memulai Telegram Bot");

  teBot.wifiConnect(ssid, pass);
  teBot.setTelegramToken(token);
  servo.attach(14);
  servo.write(0);
  pinMode(led, OUTPUT);

  if(teBot.testConnection()) 
    Serial.println("\nkoneksi Ok");
  else
    Serial.println("\nkoneksi tidak baik");

}


void telegram () {
  TBMessage msg;

  curentTime = millis();
  previousTime = curentTime;
  if(teBot.getNewMessage(msg) && curentTime - previousTime <= timeoutTime) { 
    curentTime = millis();   
    //if(teBot.getNewMessage(msg)) {
      if(msg.text.equalsIgnoreCase("/send")){
        servo.write(80);
        delay(100);
        servo.write(0);
        teBot.sendMessage(msg.sender.id, "Ikan sudah di beri makan");
      }
      else if(msg.text.equalsIgnoreCase("/on")){
        digitalWrite(led, LOW);
        teBot.sendMessage(msg.sender.id, "led on");
      }
      else if(msg.text.equalsIgnoreCase("/off")){
        digitalWrite(led, HIGH);
        teBot.sendMessage(msg.sender.id, "led off");
      }
      else {
        String ulang;
        ulang = (String)"Welcome" + msg.sender.username + (String)"Ketik (/send) (/on) dan (/off) untuk menghidupkan led";
        teBot.sendMessage(msg.sender.id, ulang);
      }
  }
  curentTime = millis();   
}


void waktu () {
  DateTime now = rtc.now();
  Serial.print(now.hour());
  Serial.print(':');
  Serial.println(now.minute());
  //int displaytime = (now.hour() * 100) + now.minute();
  //display.showNumberDecEx(displaytime, 0b11100000, true);
  if(now.hour() == 7 && now.minute()== 0 && now.second() ==0) {
    for(pos = 0; pos <= 80; pos += 1) {
      servo.write(pos);
      delay(5);
    }
    for(pos = 80; pos >= 0; pos -= 1) {
      servo.write(pos);
      delay(5);
    }
  }
  if(now.hour() == 16 && now.minute()== 0 && now.second() ==0) {
    for(pos = 0; pos <= 80; pos += 1) {
      servo.write(pos);
      delay(5);
    }
    for(pos = 80; pos >= 0; pos -= 1) {
      servo.write(pos);
      delay(5);
    }
  }
  delay(1000);
}


void loop () {
  telegram();
  waktu();
  delay(200);
}
