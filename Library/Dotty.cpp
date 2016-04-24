#include "Arduino.h"
#include "Dotty.h"
#include "Wire.h"

void Dotty::start()
{
	Wire.begin();   //starts the lib

  StartMCP0();

  StartMCP1();

  StartRTC();

  pinMode(12, INPUT);

  pinMode(13, INPUT);

  pinMode(13, INPUT);

  Serial.begin(9600);   //for debug purpose only!
}

int Dotty::hours(){
  Wire.beginTransmission(0x68);
  Wire.write(0x03);
  hour=Wire.read();
  Wire.endTransmission();
  return hour;
  }

int Dotty::minutes(){
  Wire.beginTransmission(0x68);
  Wire.write(0x02);
  minute=Wire.read();
  Wire.endTransmission();
  return minute;
  }

int Dotty::seconds(){
  Wire.beginTransmission(0x68);
  Wire.write(0x01);
  second=Wire.read();
  Wire.endTransmission();
  return second;
  }

int Dotty::days(){
  Wire.beginTransmission(0x68);
  Wire.write(0x06);
  day=Wire.read();
  Wire.endTransmission();
  return day;
  }

int Dotty::months(){
  Wire.beginTransmission(0x68);
  Wire.write(0x06);
  month=Wire.read();
  Wire.endTransmission();
  return month;
  }

int Dotty::years(){
  Wire.beginTransmission(0x68);
  Wire.write(0x07);
  year=Wire.read();
  Wire.endTransmission();
  return year;
  }

int Dotty::temps(){
  temp= analogRead(A0);
  return temp;
  }

bool Dotty::beep(){

  }

bool Dotty::buzzer(){

  }

void Dotty::StartRTC(){
    Wire.beginTransmission(0x68);
    Wire.write(0x07);
    Wire.write(B00010011);  //here we set the pins 8-16 like outputs.
    Wire.endTransmission();
  }

void Dotty::StartMCP0(){
    Wire.beginTransmission(0x20);   //open the i2c bus on 0x20 address
  Wire.write(0x05);     //here you can select the address to read or write. The MCPs have this charateristic: before write the number of the address, then write the address itself.
                        //please refer to the datasheet for more information.
  byte a = B00100000;   //Here we're setting the base register. @pag. 8 of the microchip datasheet you can find the explanation for the 0s and 1s.
  Wire.write(a);        //effectivily write the register
  Wire.endTransmission();   //closing the communication, you'll have to communicate with another ic, and so another address!

  Wire.beginTransmission(0x20);   //there's the same as before, but here we're setting the input and outputs of the mcps. 
                                  //in our case, they're all output, since they have to power up the display.
  Wire.write(0x00);
  a = B00000000;    //here we set the pins 0-7 like outputs.
  Wire.write(a);
  Wire.endTransmission();

  //even if we selected before on the 0x05 register the sequential operation (in order to have more speed), 
  //this code is going to run only once at first startup, so we don't mind for the time it occurs.


  Wire.beginTransmission(0x20);
  Wire.write(0x01);
  a = B00000000;    //here we set the pins 8-16 like outputs.
  Wire.write(a);
  Wire.endTransmission(); 
}   

void Dotty::StartMCP1() {
    //Below the same as before for the 0x21 MPC.

  Wire.beginTransmission(0x21);
  Wire.write(0x05);
  byte a = B00000000;
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

  }


  int Dotty::NumDivUni(int times){

  //With this function we divede the number in 4 digits, so we call "s" the thousands, "p" the thousands, "q" the decine, "r" the units.

  int s = tempo / 1000;
  int p = (tempo / 100) - s * 10;
  int q = (tempo / 10) - s * 100 - p * 10;
  int r = (tempo / 1) - s * 1000 - p * 100 - q * 10;

  return r;

  }

  int Dotty::NumDivDec(int times){

  //With this function we divede the number in 4 digits, so we call "s" the thousands, "p" the thousands, "q" the decine, "r" the units.

  int s = tempo / 1000;
  int p = (tempo / 100) - s * 10;
  int q = (tempo / 10) - s * 100 - p * 10;
  int r = (tempo / 1) - s * 1000 - p * 100 - q * 10;

  return q;

  }

  int Dotty::NumDivHun(int times){

  //With this function we divede the number in 4 digits, so we call "s" the thousands, "p" the thousands, "q" the decine, "r" the units.

  int s = tempo / 1000;
  int p = (tempo / 100) - s * 10;
  int q = (tempo / 10) - s * 100 - p * 10;
  int r = (tempo / 1) - s * 1000 - p * 100 - q * 10;

  return p;

  }

  int Dotty::NumDivThu(int times){

  //With this function we divede the number in 4 digits, so we call "s" the thousands, "p" the thousands, "q" the decine, "r" the units.

  int s = tempo / 1000;
  int p = (tempo / 100) - s * 10;
  int q = (tempo / 10) - s * 100 - p * 10;
  int r = (tempo / 1) - s * 1000 - p * 100 - q * 10;

  return s;

  }

  int Dotty::NumDivUni1(int times1){

  //With this function we divede the number in 4 digits, so we call "s" the thousands, "p" the thousands, "q" the decine, "r" the units.

  int s = tempo / 1000;
  int p = (tempo / 100) - s * 10;
  int q = (tempo / 10) - s * 100 - p * 10;
  int r = (tempo / 1) - s * 1000 - p * 100 - q * 10;

  return r;;

  }

  int Dotty::NumDivDec1(int times1){

  //With this function we divede the number in 4 digits, so we call "s" the thousands, "p" the thousands, "q" the decine, "r" the units.

  int s = tempo / 1000;
  int p = (tempo / 100) - s * 10;
  int q = (tempo / 10) - s * 100 - p * 10;
  int r = (tempo / 1) - s * 1000 - p * 100 - q * 10;

  return q;

  }

  int Dotty::NumDivHun1(int times1){

  //With this function we divede the number in 4 digits, so we call "s" the thousands, "p" the thousands, "q" the decine, "r" the units.

  int s = tempo / 1000;
  int p = (tempo / 100) - s * 10;
  int q = (tempo / 10) - s * 100 - p * 10;
  int r = (tempo / 1) - s * 1000 - p * 100 - q * 10;

  return p;

  }

  int Dotty::NumDivThu1(int times1){

  //With this function we divede the number in 4 digits, so we call "s" the thousands, "p" the thousands, "q" the decine, "r" the units.

  int s = tempo / 1000;
  int p = (tempo / 100) - s * 10;
  int q = (tempo / 10) - s * 100 - p * 10;
  int r = (tempo / 1) - s * 1000 - p * 100 - q * 10;

  return s;

  }


void Dotty::Display(int s, int p, int q, int r){
  for(int k=0; k<7; k++)
  

  //What we're doing here is to put one pin after one to ground for allow the decided row to turn on. 
  //As I said in the wiki, the electrical caratheristic of the display permit us to use directly the MCPs without the need of NPN arrays
  //So, we sequentially put one pin (one row) to ground in order to close the circuit and let the leds on that row turn on!

  Wire.beginTransmission(0x20);   //same as before, initialize communication, address the address and then write!
  Wire.write(0x12);
  b=B10111111;
  Wire.write(b);
  Wire.write(b);                  //one little differece: here we're using the sequential writing in order to make the code run faster. 
                                  //That means that the register will increase automatically, without the need to close and open the bus.
  Wire.endTransmission();

  //with this, we're going to control the anodes of the leds. We initialize another variable, and then use the arrays saw before for creating numbers.
  //Have a look at the value of c: we're using the bit math to shift the 0s and 1s of the numbers to allow multiple numbers on one same row.
  //So we shift the first number of a row by 0 position, because it has to be at the edge of the display, and the successive of 4 position, the 3 of the previus one and 1 of spacing.
  //again, for the third and fouth number, we shift it by 1 position for spacing, and the other by 5 positions, 1+3+1.

  

  Wire.beginTransmission(0x21);
  Wire.write(0x12);
  c = numer1[s + linea] | (numer1[p + linea] >> 4);
  Wire.write(c);
  c = (numer1[q + linea] >> 1) | (numer1[r + linea] >> 5);
  Wire.write(c);
  c = B00000000;
  Wire.write(c);
  Wire.write(c);
  Wire.endTransmission();

  b=b>>1;  //here we go on the next row
  
  linea=linea+11;

  //and that repeats until the end of the code!

}

void Dotty::Display1(int s1, int p1, int q1, int r1){
  for(int k=0; k<7; k++)
  

  //What we're doing here is to put one pin after one to ground for allow the decided row to turn on. 
  //As I said in the wiki, the electrical caratheristic of the display permit us to use directly the MCPs without the need of NPN arrays
  //So, we sequentially put one pin (one row) to ground in order to close the circuit and let the leds on that row turn on!

  Wire.beginTransmission(0x20);   //same as before, initialize communication, address the address and then write!
  Wire.write(0x12);
  b=B10111111;
  Wire.write(b);
  Wire.write(b);                  //one little differece: here we're using the sequential writing in order to make the code run faster. 
                                  //That means that the register will increase automatically, without the need to close and open the bus.
  Wire.endTransmission();

  //with this, we're going to control the anodes of the leds. We initialize another variable, and then use the arrays saw before for creating numbers.
  //Have a look at the value of c: we're using the bit math to shift the 0s and 1s of the numbers to allow multiple numbers on one same row.
  //So we shift the first number of a row by 0 position, because it has to be at the edge of the display, and the successive of 4 position, the 3 of the previus one and 1 of spacing.
  //again, for the third and fouth number, we shift it by 1 position for spacing, and the other by 5 positions, 1+3+1.

  

  Wire.beginTransmission(0x21);
  Wire.write(0x12);
  c = numer1[s + linea] | (numer1[p + linea] >> 4);
  Wire.write(c);
  c = (numer1[q + linea] >> 1) | (numer1[r + linea] >> 5);
  Wire.write(c);
  c = B00000000;
  Wire.write(c);
  Wire.write(c);
  Wire.endTransmission();

  b=b>>1;  //here we go on the next row

  linea=linea+11;
  
  //and that repeats until the end of the code!

}

bool Dotty::button1(){
  bool switch1=digitalRead(12);
  return switch1;

}

bool Dotty::button2(){
  bool switch2=digitalRead(11);
  return switch2;
}

bool Dotty::button3(){
  bool switch3=digitalRead(10);
  return switch3;
}

void Dotty::displaySelection(){
  if(button3()==true && button2()==true){
    times=(hours()+trimmer())*100+(minutes()+trimmer());
    times1=temps()*100;
  }
  if(button3()==true && button2()==false){
    times=(hours()+trimmer())*100+(minutes()+trimmer());
    times1=(days()+trimmer1())*100+(months()+trimmer1());
  }

  if(button3()==false && button2()==true){
    times=(days()+trimmer())*100+(months()+trimmer());
    times1=years()+trimmer1();
  }

  if(button3()==false && button2()==false){
    times=(hours()+trimmer())*100+(minutes()+trimmer());
    times1=(hours()+trimmer1())*100+(minutes()+trimmer1());
  }
}

int Dotty::trimmer1(){
  if (button4()==true && button5()==true){

      switch (button5()) {
      case true:
        trim1=trim1+1;
        break;
      case false:
      trim1=trim1;
    }

  }
return trim1;
}

int Dotty::trimmer(){
  if (button4()==true && button5()==true){

    switch (button4()) {
      case true:
        trim=trim+1;
        break;
      case false:
      trim=0;
    }

}

return trim;

}

int Dotty::clapper(){
  int clap=analogRead(A1);
  return clap;
}

void Dotty::clapperdisplay(){
  if(button1()==true){
    if(clapper()>100){
      Display(s, p, q, r);
      Display1(s1, p1, q1, r1);
    }
  }
if (button1()==false){
      Display(s, p, q, r);
      Display1(s1, p1, q1, r1);
}
}
void Dotty::displayblank(){
  Wire.beginTransmission(0x20);   //same as before, initialize communication, address the address and then write!
  Wire.write(0x12);
  byte b=B11111111;
  Wire.write(b);
  Wire.write(b);                  //one little differece: here we're using the sequential writing in order to make the code run faster. 
                                  //That means that the register will increase automatically, without the need to close and open the bus.
  Wire.endTransmission();

  //with this, we're going to control the anodes of the leds. We initialize another variable, and then use the arrays saw before for creating numbers.
  //Have a look at the value of c: we're using the bit math to shift the 0s and 1s of the numbers to allow multiple numbers on one same row.
  //So we shift the first number of a row by 0 position, because it has to be at the edge of the display, and the successive of 4 position, the 3 of the previus one and 1 of spacing.
  //again, for the third and fouth number, we shift it by 1 position for spacing, and the other by 5 positions, 1+3+1.

  

  Wire.beginTransmission(0x21);
  Wire.write(0x12);
  byte c = B00000000;
  Wire.write(c);
  Wire.write(c);
  Wire.endTransmission();
}