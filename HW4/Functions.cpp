#include <stdio.h>
#include <string>
using namespace std; // using the "std" namespace

struct month
{
  string name;
  int length;
} year[12];

year[0] = {.name = "January", .length = 31};
year[1] = {.name = "February", .length = 28};
year[2] = {.name = "March", .length = 31};
year[3] = {.name = "April", .length = 30};
year[4] = {.name = "May", .length = 31};
year[5] = {.name = "June", .length = 30};
year[6] = {.name = "July", .length = 31};
year[7] = {.name = "August", .length = 31};
year[8] = {.name = "September", .length = 30};
year[9] = {.name = "October". .length = 31};
year[10] = {.name = "November", .length = 30};
year[11] = {.name = "December", .length = 31};

string week [7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void ByEleven(int max) // max here should be 1000. I decided to make it variable because YOLO.
{
  int x = 0;
  while (x<=max)
  {
    if (x % 11 == 0)
    {
      cout << x << ", " << endl; //prints out the multiple of eleven and a comma.
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
      cout << year[i].month << " " << j << ": " << week[dayCounter%7];
      dayCounter = (dayCounter + 1) % 7; //increments dayCounter (keeps range between 0 and 6)
    }
  }
}

void CalPrint2018() // prints the calendar for 2018
{
  CalPrint(1);
}
