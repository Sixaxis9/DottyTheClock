#include <Wire.h>

void setup()
{
  pinMode(13, OUTPUT);
  Wire.begin();

  Wire.beginTransmission(0x20);
  Wire.write(0x05);
  byte a = B00100000;
  Wire.write(a);
  Wire.endTransmission();

  Wire.beginTransmission(0x20);
  Wire.write(0x00);
  a = B00000000;
  Wire.write(a);
  Wire.endTransmission();


  Wire.beginTransmission(0x20);
  Wire.write(0x01);
  a = B00000000;
  Wire.write(a);
  Wire.endTransmission();



  Wire.beginTransmission(0x21);
  Wire.write(0x05);
  a = B00000000;
  Wire.write(a);
  Wire.endTransmission();

  Wire.beginTransmission(0x21);
  Wire.write(0x00);
  a = B00000000;
  Wire.write(a);
  Wire.endTransmission();




  Wire.beginTransmission(0x21);
  Wire.write(0x01);
  a = B00000000;
  Wire.write(a);
  Wire.endTransmission();

  Serial.begin(9600);

  

}

void loop() {

  byte numer1[] = {B11100000, B00100000, B11100000, B11100000, B10100000, B11100000, B11100000, B11100000, B11100000, B11100000, B11100000};
  byte numer2[] = {B10100000, B01100000, B10100000, B00100000, B10100000, B10000000, B10000000, B00100000, B10100000, B10100000, B10100000};
  byte numer3[] = {B10100000, B10100000, B00100000, B00100000, B10100000, B10000000, B10000000, B00100000, B10100000, B10100000, B10100000};
  byte numer4[] = {B10100000, B00100000, B11100000, B01100000, B11100000, B11100000, B11100000, B01000000, B11100000, B11100000, B10100000};
  byte numer5[] = {B10100000, B00100000, B10000000, B00100000, B00100000, B00100000, B10100000, B01000000, B10100000, B00100000, B10100000};
  byte numer6[] = {B10100000, B00100000, B10000000, B00100000, B00100000, B00100000, B10100000, B10000000, B10100000, B00100000, B10100000};
  byte numer7[] = {B11100000, B00100000, B11100000, B11100000, B00100000, B11100000, B11100000, B10000000, B11100000, B11100000, B11100000};

  /*
    byte numer1[]= { 32, 224, 224, 160, 224, 224, 224, 224, 224, 224};
    byte numer2[]= {96, 160, 32, 160, 128, 128, 32, 160, 160, 160};
    byte numer3[]= {160, 32, 32, 160, 128, 128, 32, 160, 160, 160};
    byte numer4[]= {32, 224, 96, 224, 224, 224, 64, 224, 224, 160};
    byte numer5[]= {32, 128, 32, 32, 32, 160, 64, 160, 32, 160};
    byte numer6[]= {32, 128, 32, 32, 32, 160, 128, 160, 32, 160};
    byte numer7[]= {32, 224, 224, 32, 224, 224, 128, 224, 224, 224};
  */
  int tempo = 2;


  int s = tempo / 1000;
  int p = (tempo / 100) - s * 10;
  int q = (tempo / 10) - s * 100 - p * 10;
  int r = (tempo / 1) - s * 1000 - p * 100 - q * 10;


  /*  Debug Purpose Only!!
    Serial.println(s);
    Serial.println(p);
    Serial.println(q);
    Serial.println(r);

    Serial.println(numer1[s], BIN);
    Serial.println(numer1[p], BIN);
    Serial.println(numer1[p]>>4, BIN);
    Serial.println(numer1[s]|(numer1[p]), BIN);
    Serial.println(numer1[s]|(numer1[p]>>4), BIN);
  */

  // int time1 = millis();


  byte  b = B01111111;

  Wire.beginTransmission(0x20); 
  Wire.write(0x12);
  Wire.write(b);
  Wire.write(b);
  Wire.endTransmission();

  byte  c = 0;

  Wire.beginTransmission(0x21);
  Wire.write(0x12);
  c = numer1[s] | (numer1[p] >> 4);
  Wire.write(c);
  c = (numer1[q] >> 1) | (numer1[r] >> 5);
  Wire.write(c);
  c = B00000000;
  Wire.write(c);
  Wire.write(c);
  Wire.endTransmission();


  b = B10111111;

  Wire.beginTransmission(0x20);
  Wire.write(0x12);
  Wire.write(b);
  Wire.write(b);
  Wire.endTransmission();

  Wire.beginTransmission(0x21);
  Wire.write(0x12);
  c = numer2[s] | (numer2[p] >> 4);
  Wire.write(c);
  c = (numer2[q] >> 1) | (numer2[r] >> 5);
  Wire.write(c);
  c = B00000000;
  Wire.write(c);
  Wire.write(c);
  Wire.endTransmission();


  b = B11011111;

  Wire.beginTransmission(0x20);
  Wire.write(0x12);
  Wire.write(b);
  Wire.write(b);
  Wire.endTransmission();

  Wire.beginTransmission(0x21);
  Wire.write(0x12);
  c = numer3[s] | (numer3[p] >> 4);
  Wire.write(c);
  c = (numer3[q] >> 1) | (numer3[r] >> 5);
  Wire.write(c);
  c = B00000000;
  Wire.write(c);
  Wire.write(c);
  Wire.endTransmission();


  b = B11101111;

  Wire.beginTransmission(0x20);
  Wire.write(0x12);
  Wire.write(b);
  Wire.write(b);
  Wire.endTransmission();

  c = B00101110;
  Wire.beginTransmission(0x21);
  Wire.write(0x12);
  c = numer4[s] | (numer4[p] >> 4);
  Wire.write(c);
  c = (numer4[q] >> 1) | (numer4[r] >> 5);
  Wire.write(c);
  c = B00000000;
  Wire.write(c);
  Wire.write(c);
  Wire.endTransmission();



  b = B11110111;

  Wire.beginTransmission(0x20);
  Wire.write(0x12);
  Wire.write(b);
  Wire.write(b);
  Wire.endTransmission();

  Wire.beginTransmission(0x21);
  Wire.write(0x12);
  c = numer5[s] | (numer5[p] >> 4);
  Wire.write(c);
  c = (numer5[q] >> 1) | (numer5[r] >> 5);
  Wire.write(c);
  c = B00000000;
  Wire.write(c);
  Wire.write(c);
  Wire.endTransmission();

  b = B11111011;

  Wire.beginTransmission(0x20);
  Wire.write(0x12);
  Wire.write(b);
  Wire.write(b);
  Wire.endTransmission();

  Wire.beginTransmission(0x21);
  Wire.write(0x12);
  c = numer6[s] | (numer6[p] >> 4);
  Wire.write(c);
  c = (numer6[q] >> 1) | (numer6[r] >> 5);
  Wire.write(c);
  c = B00000000;
  Wire.write(c);
  Wire.write(c);
  Wire.endTransmission();

  b = B11111101;

  Wire.beginTransmission(0x20);
  Wire.write(0x12);
  Wire.write(b);
  Wire.write(b);
  Wire.endTransmission();

  Wire.beginTransmission(0x21);
  Wire.write(0x12);
  c = numer7[s] | (numer7[p] >> 4);
  Wire.write(c);
  c = (numer7[q] >> 1) | (numer7[r] >> 5);
  Wire.write(c);
  c = B00000000;
  Wire.write(c);
  Wire.write(c);
  Wire.endTransmission();


  //int time2 = millis() - time1;
  //Serial.println(time2);

}
