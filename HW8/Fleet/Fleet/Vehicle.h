#pragma once
#include <iostream>
#include <utility>
#include <memory>
#include <vector>

using namespace std;

class Vehicle
{
public:
	Vehicle();
	virtual ~Vehicle();
	void SendToLocation(std::pair<double, double> location);
	void MoveLocation(std::pair<double, double> locPair);
	virtual void Status();
	std::string getLocation();
	pair<double, double> getLocationPair();
private:
	std::pair<double, double> currentLocation;

};

