#include <stdio.h>
#include <string>
#include <iostream>
#include "Functions.h"
using namespace std; // using the "std" namespace

struct Month
{
	string name;
	int length;

	Month(string n, int len) {
		name = n;
		length = len;
	}

	Month() {
		name;
		length = 0;
	}
};


Month year[12] = { Month("January", 31), Month("February", 28), Month("March", 31), Month("April", 30), Month("May", 31), Month("June", 30), Month("July", 31), Month("August", 31), Month("September", 30), Month("October", 31), Month("November", 30), Month("December", 31) };


string week [7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void ByEleven(int max) // max here should be 1000. I decided to make it variable because YOLO.
{
  int x = 0;
  while (x<=max)
  {
    if (x % 11 == 0)
    {
		if (max - x > 11) {
			cout << x << ", " << endl; //prints out the multiple of eleven and a comma.
		}
		else {
			cout << x << " and a partridge in a pear tree!" << endl; //prints out the multiple of eleven and a comma.
		}
    }
    x++; //increase value of x by 1.
  }
}

void ByEleven() // default ByEleven function. Takes no inputs, so this is the actual answer to the homework problem.
{
  ByEleven(1000);
}

void CalPrint(int first_day) // Prints the yearly calendar
{
  int dayCounter = first_day;
  for (int i = 0; i < 12; i++)
  {
    for (int j = 1; j <= year[i].length; j++ ) { // goes through each day of the month
      cout << year[i].name << " " << j << ": " << week[dayCounter%7] << endl;
      dayCounter = (dayCounter + 1) % 7; //increments dayCounter (keeps range between 0 and 6)
    }
  }
}

void CalPrint2018() // prints the calendar for 2018
{
  CalPrint(1);
}
