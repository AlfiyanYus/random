#include <Wire.h>
#include "RTClib.h"
#include <TM1637Display.h>
#define CLK 2
#define DIO 3
TM1637Display display(CLK, DIO);
DS3231  rtc(SDA, SCL); 
// Module connection pins (Digital Pins)

Time  t;
unsigned int h,m,s;
byte f;
//=========================
void setup() {
rtc.begin();
display.setBrightness(0x0f);
//--------------------------------------------------------------
//aktifkan baris perintah ini untuk seting RTC
//lakukan jika waktu tidak sesuai
//cukup sekali saja, setelah itu di-non-aktifkan lagi perintahnya
//rtc.setDate(11,10,2019);  //setting tanggal 11 Oktober 2019
//rtc.setTime(8, 15, 00);   //setting jam 08:15:00
//rtc.setDOW(5);            //setting hari Jumat, 0=Minggu,1=Senin
//--------------------------------------------------------------- 

} 
//================== 
void loop()
{
 t=rtc.DateTime();
 h=t.hour,DEC;
 m=t.min,DEC;
 s=t.sec,DEC; 
 h=(h*100+m);
 if(f==0){
  display.showNumberDecEx(h, 64); 
  f=1;}
 else{
  display.showNumberDecEx(h, 0); 
  f=0;
    }
 }
