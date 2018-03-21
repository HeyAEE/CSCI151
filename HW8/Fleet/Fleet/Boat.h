#pragma once
#include "Vehicle.h"
#include <string>
using namespace std;
class Boat :
	public Vehicle
{
public:
	Boat(string nameString, double cargoDoub);
	virtual ~Boat();
	void Status() override;
private:
	string name;
	double cargoSize;
};

