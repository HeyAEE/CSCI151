#pragma once
#include <string>

struct month
{
  std::string name;
  int length;
};

month year[12];

void ByEleven(int max);
void ByEleven();
void CalPrint2018();
void CalPrint(int first_day);
