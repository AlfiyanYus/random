#include "CTBot.h"
#include <Servo.h>
#define led D4

Servo servo;
CTBot teBot;

char* ssid = "Alfyan_yu";
char* pass = "what are you say";
char* token = "1534144953:AAGBCRs_yEIIj37YDZ5CU-3st58n11IGKPI";

unsigned long curentTime;
unsigned long previousTime = 0;
const int timeoutTime = 2000;


void setup() {
  Serial.begin(115200);
  Serial.println("Memulai Telegram Bo");

  teBot.wifiConnect(ssid, pass);
  teBot.setTelegramToken(token);
  servo.attach(14);
  servo.write(90);
  pinMode(led, OUTPUT);

  if(teBot.testConnection()) 
    Serial.println("\nkoneksi Ok");
  else
    Serial.println("\nkoneksi tidak baik");

  
}

void loop() {
  TBMessage msg;

  curentTime = millis();
  previousTime = curentTime;
  while (teBot.getNewMessage(msg) && curentTime - previousTime <= timeoutTime) { 
    curentTime = millis();   
    //if(teBot.getNewMessage(msg)) {
      if(msg.text.equalsIgnoreCase("/send")){
        digitalWrite(led, HIGH);
        servo.write(130);
        delay(100);
        servo.write(90);
        teBot.sendMessage(msg.sender.id, "led off");
      }
      else if(msg.text.equalsIgnoreCase("/on")){
        digitalWrite(led, LOW);
        teBot.sendMessage(msg.sender.id, "led on");
      }
      else {
        String ulang;
        ulang = (String)"Welcome" + msg.sender.username + (String)"Ketik (/send) dan (/lock) untuk menghidupkan led";
        teBot.sendMessage(msg.sender.id, ulang);
      }
  }
  curentTime = millis();   
}
