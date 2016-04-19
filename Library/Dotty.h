/*
Created by Marco Giordano
Library of the Dotty Project
For more, please visit the kickstarter page
*/

#ifndef Dotty_h
#define Dotty_h
#include "Arduino.h"

class Dotty
{
public:
	void start();
	int hours();
	int minutes();
	int seconds();
	int days();
	int months();
	int years();
	int temps();
	bool beep();
	bool buzzer();
	int temperature;
	void StartRTC();
	void StartMCP0();
	void StartMCP1();


private:

	int hour;
	int minute;
	int second;
	int day;
	int month;
	int year;
	int temp;
	int s;
	int p;
	int q;
	int r;
	int s1;
	int p1;
	int q1;
	int r1;	
	int tempo;
	int tempo1;


	

	byte numer1[77] = {B11100000, B00100000, B11100000, B11100000, B10100000, B11100000, B11100000, B11100000, B11100000, B11100000, B11100000,
  	 				   B10100000, B01100000, B10100000, B00100000, B10100000, B10000000, B10000000, B00100000, B10100000, B10100000, B10100000,
  	 				   B10100000, B10100000, B00100000, B00100000, B10100000, B10000000, B10000000, B00100000, B10100000, B10100000, B10100000,
  	   				   B10100000, B00100000, B11100000, B01100000, B11100000, B11100000, B11100000, B01000000, B11100000, B11100000, B10100000,
  	 				   B10100000, B00100000, B10000000, B00100000, B00100000, B00100000, B10100000, B01000000, B10100000, B00100000, B10100000,
  					   B10100000, B00100000, B10000000, B00100000, B00100000, B00100000, B10100000, B10000000, B10100000, B00100000, B10100000,
  					   B11100000, B00100000, B11100000, B11100000, B00100000, B11100000, B11100000, B10000000, B11100000, B11100000, B11100000};

  	 int NumDivUni(int times);
	 int NumDivDec(int times);
  	 int NumDivHun(int times);
  	 int NumDivThu(int times);
  	 int NumDivUni1(int times1);
  	 int NumDivDec1(int times1);
  	 int NumDivHun1(int times1);
  	 int NumDivThu1(int times1);
  	 void Display(int s, int p, int q, int r);
  	 void Display1(int s1, int p1, int q1, int r1);
  	 byte  b = 0;
  	 byte  c = 0;
  	 int linea;


};
#endif