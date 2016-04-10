/* 
Hi! That's a commented sketch about the dotty project! For knowing more about the project, please refere to the kickstarter page:
I tryied to comment every important line, if something is not cleare, please leave a comment on the GitHub repository! And please also report 
any suggestion or bug you find. Thank you for your attention!
Marco Giordano, 10/04/2016.
*/


#include <Wire.h>   //initialize the i2c lib

void setup()
{

  Wire.begin();   //starts the lib

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

  //Below the same as before for the 0x21 MPC.

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

//  Serial.begin(9600);   //for debug purpose only!

  

}

  //That's the loop code! Here it will run indefenitely until the power drops. Let's analyze the main functions!
  
void loop() {

  //What's below are 7 arrys, in which are stored the information to make the numbers. When you enter a number, it will output the right sequence of bits in order to display the number.
  //In fact if you look at the bits in vertical, they look like the number you'll display on dotty! 0s corrisponds to off leds, 1s to on leds.
  //So we only need to enter a number in the right array to have the right sequence of bits and then display they in (vertical) sequence. Let's go on!

  byte numer1[] = {B11100000, B00100000, B11100000, B11100000, B10100000, B11100000, B11100000, B11100000, B11100000, B11100000, B11100000};
  byte numer2[] = {B10100000, B01100000, B10100000, B00100000, B10100000, B10000000, B10000000, B00100000, B10100000, B10100000, B10100000};
  byte numer3[] = {B10100000, B10100000, B00100000, B00100000, B10100000, B10000000, B10000000, B00100000, B10100000, B10100000, B10100000};
  byte numer4[] = {B10100000, B00100000, B11100000, B01100000, B11100000, B11100000, B11100000, B01000000, B11100000, B11100000, B10100000};
  byte numer5[] = {B10100000, B00100000, B10000000, B00100000, B00100000, B00100000, B10100000, B01000000, B10100000, B00100000, B10100000};
  byte numer6[] = {B10100000, B00100000, B10000000, B00100000, B00100000, B00100000, B10100000, B10000000, B10100000, B00100000, B10100000};
  byte numer7[] = {B11100000, B00100000, B11100000, B11100000, B00100000, B11100000, B11100000, B10000000, B11100000, B11100000, B11100000};



  /*  Same in decimal valiues, just debug.
   *   
    byte numer1[]= { 32, 224, 224, 160, 224, 224, 224, 224, 224, 224};
    byte numer2[]= {96, 160, 32, 160, 128, 128, 32, 160, 160, 160};
    byte numer3[]= {160, 32, 32, 160, 128, 128, 32, 160, 160, 160};
    byte numer4[]= {32, 224, 96, 224, 224, 224, 64, 224, 224, 160};
    byte numer5[]= {32, 128, 32, 32, 32, 160, 64, 160, 32, 160};
    byte numer6[]= {32, 128, 32, 32, 32, 160, 128, 160, 32, 160};
    byte numer7[]= {32, 224, 224, 32, 224, 224, 128, 224, 224, 224};
  */
  
  int tempo = 2020;   //here's the number you'll display in the upper 8*16 display of dotty! A curiosity: the name "tempo" comes from Italian and means time! ;)

  //With this function we divede the number in 4 digits, so we call "s" the thousands, "p" the thousands, "q" the decine, "r" the units.

  int s = tempo / 1000;
  int p = (tempo / 100) - s * 10;
  int q = (tempo / 10) - s * 100 - p * 10;
  int r = (tempo / 1) - s * 1000 - p * 100 - q * 10;

  //Same as before, for the second 8*16 display of Dotty.

   int tempo1 = 1224;


  int s1 = tempo1 / 1000;
  int p1 = (tempo1 / 100) - s1 * 10;
  int q1 = (tempo1 / 10) - s1 * 100 - p1 * 10;
  int r1 = (tempo1 / 1) - s1 * 1000 - p1 * 100 - q1 * 10;


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
 

  // int time1 = millis();
 */

  //Here we comes at the central part of code, we're finally writing the values on the MCPs!

  byte  b = 0;

  //What we're doing here is to put one pin after one to ground for allow the decided row to turn on. 
  //As I said in the wiki, the electrical caratheristic of the display permit us to use directly the MCPs without the need of NPN arrays
  //So, we sequentially put one pin (one row) to ground in order to close the circuit and let the leds on that row turn on!

  Wire.beginTransmission(0x20);   //same as before, initialize communication, address the address and then write!
  Wire.write(0x12);
  b=B10111111;
  Wire.write(b);
  b=B11111111;
  Wire.write(b);                  //one little differece: here we're using the sequential writing in order to make the code run faster. 
                                  //That means that the register will increase automatically, without the need to close and open the bus.
  Wire.endTransmission();

  //with this, we're going to control the anodes of the leds. We initialize another variable, and then use the arrays saw before for creating numbers.
  //Have a look at the value of c: we're using the bit math to shift the 0s and 1s of the numbers to allow multiple numbers on one same row.
  //So we shift the first number of a row by 0 position, because it has to be at the edge of the display, and the successive of 4 position, the 3 of the previus one and 1 of spacing.
  //again, for the third and fouth number, we shift it by 1 position for spacing, and the other by 5 positions, 1+3+1.

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

  //and that repeats until the end of the code!

  b = B11011111;

  Wire.beginTransmission(0x20);
  Wire.write(0x12);
  Wire.write(b);
  b=B11111111;
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


  b = B11101111;

  Wire.beginTransmission(0x20);
  Wire.write(0x12);
  Wire.write(b);
  b=B11111111;
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


  b = B11110111;

  Wire.beginTransmission(0x20);
  Wire.write(0x12);
  Wire.write(b);
  b=B11111111;
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



  b = B11111011;

  Wire.beginTransmission(0x20);
  Wire.write(0x12);
  Wire.write(b);
  b=B11111111;
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

  b = B11111101;

  Wire.beginTransmission(0x20);
  Wire.write(0x12);
  Wire.write(b);
  b=B11111111;
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

  b = B11111110;

  Wire.beginTransmission(0x20);
  Wire.write(0x12);
  Wire.write(b);
  b=B11111111;
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


//  Here we have the "second 8*16 display". What does it change in the code? Nothing! Unless the shift of 1 position for spacing in rows (cathode).


  Wire.beginTransmission(0x20); 
  Wire.write(0x12);
  b=B11111111;
  Wire.write(b);
  b=B01111111;
  Wire.write(b);
  Wire.endTransmission();

    c = 0;

  Wire.beginTransmission(0x21);
  Wire.write(0x12);
  c = numer1[s1] | (numer1[p1] >> 4);
  Wire.write(c);
  c = (numer1[q1] >> 1) | (numer1[r1] >> 5);
  Wire.write(c);
  c = B00000000;
  Wire.write(c);
  Wire.write(c);
  Wire.endTransmission();


  b = B11111111;

  Wire.beginTransmission(0x20);
  Wire.write(0x12);
  Wire.write(b);
  b=B10111111;
  Wire.write(b);
  Wire.endTransmission();

  Wire.beginTransmission(0x21);
  Wire.write(0x12);
  c = numer2[s1] | (numer2[p1] >> 4);
  Wire.write(c);
  c = (numer2[q1] >> 1) | (numer2[r1] >> 5);
  Wire.write(c);
  c = B00000000;
  Wire.write(c);
  Wire.write(c);
  Wire.endTransmission();


  b = B11111111;

  Wire.beginTransmission(0x20);
  Wire.write(0x12);
  Wire.write(b);
  b=B11011111;
  Wire.write(b);
  Wire.endTransmission();

  Wire.beginTransmission(0x21);
  Wire.write(0x12);
  c = numer3[s1] | (numer3[p1] >> 4);
  Wire.write(c);
  c = (numer3[q1] >> 1) | (numer3[r1] >> 5);
  Wire.write(c);
  c = B00000000;
  Wire.write(c);
  Wire.write(c);
  Wire.endTransmission();


  b = B11111111;

  Wire.beginTransmission(0x20);
  Wire.write(0x12);
  Wire.write(b);
  b=B11101111;
  Wire.write(b);
  Wire.endTransmission();

  c = B00101110;
  Wire.beginTransmission(0x21);
  Wire.write(0x12);
  c = numer4[s1] | (numer4[p1] >> 4);
  Wire.write(c);
  c = (numer4[q1] >> 1) | (numer4[r1] >> 5);
  Wire.write(c);
  c = B00000000;
  Wire.write(c);
  Wire.write(c);
  Wire.endTransmission();



  b = B11111111;

  Wire.beginTransmission(0x20);
  Wire.write(0x12);
  Wire.write(b);
  b=B11110111;
  Wire.write(b);
  Wire.endTransmission();

  Wire.beginTransmission(0x21);
  Wire.write(0x12);
  c = numer5[s1] | (numer5[p1] >> 4);
  Wire.write(c);
  c = (numer5[q1] >> 1) | (numer5[r1] >> 5);
  Wire.write(c);
  c = B00000000;
  Wire.write(c);
  Wire.write(c);
  Wire.endTransmission();

  b = B11111111;

  Wire.beginTransmission(0x20);
  Wire.write(0x12);
  Wire.write(b);
  b=B11111011;
  Wire.write(b);
  Wire.endTransmission();

  Wire.beginTransmission(0x21);
  Wire.write(0x12);
  c = numer6[s1] | (numer6[p1] >> 4);
  Wire.write(c);
  c = (numer6[q1] >> 1) | (numer6[r1] >> 5);
  Wire.write(c);
  c = B00000000;
  Wire.write(c);
  Wire.write(c);
  Wire.endTransmission();

  b = B11111111;

  Wire.beginTransmission(0x20);
  Wire.write(0x12);
  Wire.write(b);
  b=B11111101;
  Wire.write(b);
  Wire.endTransmission();

  Wire.beginTransmission(0x21);
  Wire.write(0x12);
  c = numer7[s1] | (numer7[p1] >> 4);
  Wire.write(c);
  c = (numer7[q1] >> 1) | (numer7[r1] >> 5);
  Wire.write(c);
  c = B00000000;
  Wire.write(c);
  Wire.write(c);
  Wire.endTransmission();

  //just for debug, if you're interested in displaying the loop's time.
  //int time2 = millis() - time1;
  //Serial.println(time2);

}

/*That's all! The code is just finished!
 * Shoiuld I create some functions and then call them? Of course! But that code was just for explaining, and that makes all easier.
 * Plase look also at the library to see the final code and functions!
 * Thsnk,
 * Marco Giordano.
 */
 */
