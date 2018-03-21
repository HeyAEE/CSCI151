#include "Boat.h"



Boat::Boat(string nameString, double cargoDoub)
{
	name = nameString;
	cargoSize = cargoDoub;
}


Boat::~Boat()
{
}

void Boat::Status()
{
	std::cout << "Location - " << getLocation() << ", Boat: " << "Name - " << name << ", Cargo - " << cargoSize << endl;
}