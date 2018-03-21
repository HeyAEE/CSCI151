#include "Vehicle.h"
#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <vector>
#include <cmath>

using namespace std;


Vehicle::Vehicle()
{
	currentLocation = std::pair<double, double>(47.5894610, -122.3182980); // Honey, I'm home!
}


Vehicle::~Vehicle()
{
}

void Vehicle::SendToLocation(std::pair<double, double> locPair)
{
	Vehicle::currentLocation = locPair;
}

void Vehicle::MoveLocation(std::pair<double, double> locPair)
{
	Vehicle::currentLocation = std::pair<double, double>(currentLocation.first + locPair.first, currentLocation.second - locPair.second);
}

std::string Vehicle::getLocation()
{
	std::stringstream stream;
	stream << "(" << std::to_string(currentLocation.first) << ", " << std::to_string(currentLocation.second) << ")";

	return stream.str();
}

pair<double, double> Vehicle::getLocationPair()
{
	return currentLocation;
}

void Vehicle::Status()
{
	std::cout << "Vehicle status: confirmed." << std::endl;
}