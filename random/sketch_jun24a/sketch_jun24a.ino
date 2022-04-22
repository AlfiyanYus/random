#include <TM1637Display.h>

//koneksi pin CLK ke pin 2 Arduino

//koneksi pin DIO ke pin 3 Arduino

#define CLK 2

#define DIO 3

//deklarasi variabel untuk menampilkan angka

unsigned int angka;

TM1637Display display(CLK, DIO);

 

void setup() {

  //variabel angka diisi dengan 1234

  //seting brightness maksimal

  display.setBrightness(0x0f);  

  //tampilkan nilai angka di 7 segment 

  display.showNumberDec(angka); 

}

 

void loop() {  
    for (angka = 0; angka < 1000; angka ++) {
        display.showNumberDec(angka);
        delay(100);
    }
    

}

