#include "Car.h"
#include <iostream>



Car::Car(string makeString, string modelString, long vinLong)
{
	make = makeString;
	model = modelString;
	vin = vinLong;
}


Car::~Car()
{
}

void Car::Status()
{
	std::cout << "Car: " << "Location - " << getLocation() << ", Make - " << make << ", Model - " << model << ", VIN - " << vin << endl;
}
