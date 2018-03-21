#include "Airplane.h"



Airplane::Airplane(string manString, long serLong)
{
	man = manString;
	serial = serLong;
}


Airplane::~Airplane()
{
}

void Airplane::Status()
{
	std::cout << "Airplane: " << "Location - " << getLocation() << ", Manufacturer - " << man << ", Serial - " << serial << endl;
}