#pragma once
#include "Vehicle.h"
#include <string>
using namespace std;

class Car :
	public Vehicle
{
public:
	Car(string makeString, string modelString, long vinLong);
	virtual ~Car();
	void Status() override;
private:
	string make;
	string model;
	long vin;
};

