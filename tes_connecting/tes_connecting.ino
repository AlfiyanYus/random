#include <ESP8266WiFi.h>
char *ssid = "Alfyan_yu";
char *pass = "no internet"; 


void setup() {
 Serial.begin(115200);
 WiFi.begin(ssid, pass);
 Serial.print("Connecting");
 while(WiFi.status() != WL_CONNECTED ){
  delay(500);
  Serial.print('.');
 }
 Serial.println();

 Serial.print("connected, IP adres: ");
 Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
