/*
 * Read current time with Tiny RTC module and show it to LCD (TM1637 module)
 * Author: GOlD SCREW
 * Email: goldscrewdiy@gmail.com
 * Date: Thu, 17 Dec 2020 
 */
#include <Arduino.h>
#include <SevenSegmentTM1637.h>
#include <Wire.h>
#include <TimeLib.h>
#include "RTClib.h"

// RTC
RTC_DS1307 rtc;

// 7 segment LCD: TM1637
#define CLK 2 // Digital pin 2
#define DIO 3 // Digital pin 3
SevenSegmentTM1637 MyClock(CLK, DIO);
int8_t Data[] = {0,1,2,3};
int currentHour;
int currentMinutes;
boolean isChanged;

void setup()
{
  Serial.begin(9600);  

  if (! rtc.begin()) {
   Serial.println("Couldn't find RTC");
   while (1);
  }
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
      // following line sets the RTC to the date & time this sketch was compiled
     rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));  
  }

  //MyClock.set();
  MyClock.init();
}

void loop()
{  
  // Get current datetime
  DateTime myRTC = rtc.now();
  currentHour = myRTC.hour();
  currentMinutes = myRTC.minute();
  ShowTimeOnDisplay(currentHour, currentMinutes);  

  /*if (isChanged)
  {
    MyClock.print(POINT_OFF);
    isChanged = false;
  }
  else
  {
    MyClock.print(POINT_ON);
    isChanged = true;
  }*/

  delay(1000);
}

void ShowTimeOnDisplay( int _hour, int _minute)
{
  int8_t Digit0 = _minute %10 ;
  int8_t Digit1 = (_minute % 100) / 10 ;
  int8_t Digit2 = _hour % 10 ;
  int8_t Digit3 = (_hour % 100) / 10 ;

  Data[3] = Digit0 ;
  Data[2] = Digit1 ;
  Data[1] = Digit2 ;
  Data[0] = Digit3 ;
  
 // MyClock.display(Data);
}
