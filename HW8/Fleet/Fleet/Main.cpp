#include "Boat.h"
#include "Airplane.h"
#include "Car.h"
#include <vector>
#include <memory>
#include <iterator>
#include <utility>
#include <iostream>

std::ptrdiff_t CountCars(const vector<shared_ptr<Vehicle>>& fleet)
{
	return std::distance(fleet.begin(), fleet.end());
}

std::pair<shared_ptr<Vehicle>, shared_ptr<Vehicle>> CloseAndFar(const vector<shared_ptr<Vehicle>>& fleet)
{
	auto dist = [](double xdiff, double ydiff) { return sqrt((xdiff * xdiff) + (ydiff * ydiff)); };
	pair<pair<shared_ptr<Vehicle>, double>, pair<shared_ptr<Vehicle>, double>> minmax = make_pair(make_pair(make_shared<Vehicle>(new Vehicle()), double(INT_MAX)), make_pair(make_shared<Vehicle>(new Vehicle()), double(INT_MIN))); // That's right, making nested pairs - vehicle and distance
	for (auto vehicle : fleet)
	{
		pair<double, double> currentLoc = vehicle->getLocationPair();
		double vdistance = dist(currentLoc.first, currentLoc.second);
		if (vdistance < minmax.first.second)
		{
			minmax.first.first = make_shared<Vehicle>(*vehicle);
			minmax.first.second = vdistance;
		}
		if (vdistance > minmax.second.second)
		{
			minmax.second.first = make_shared<Vehicle>(*vehicle);
			minmax.second.second = vdistance;
		}
	}
	return pair<shared_ptr<Vehicle>, shared_ptr<Vehicle>>(minmax.first.first, minmax.second.first);
}

int main()
{
	vector<Vehicle> fleet;
	vector<shared_ptr<Vehicle>> fleetPtr;
	fleet.push_back(Car{ "Tesla", "S", 12345L });
	fleet.push_back(Boat{ "Mayflower", 7.5 });
	fleet.push_back(Airplane{ "Boeing", 98765L });
	for (auto vehicle : fleet)
	{
		vehicle.Status(); // The problem is that the vehicle class has no member Status(). Only its child members have status. Basically,
						  //I'm going to make a Status interface in the vehicle class that will then be overridden by each inheriting class.
		fleetPtr.push_back(make_shared<Vehicle>(vehicle));
	}
	auto cars = CountCars(fleetPtr);
	std::cout << "There are " << cars << " cars in the fleet." << std::endl;

	// move vehicles

	for (auto vehicle : fleetPtr)
	{
		vehicle->SendToLocation(pair<double, double>{ 1.0, 1.0 });
	}
	(*(next(fleetPtr.begin(), 3)))->SendToLocation(pair<double, double>(0.5, 0.3));
	(*(prev(fleetPtr.end(), 2)))->SendToLocation(pair<double, double>(5.5, 3.3));
	// print status
	for (auto vehicle : fleetPtr)
	{
		vehicle->Status();
	}
	// find and print closest and farthest
	auto minmax = CloseAndFar(fleetPtr);
	cout << "The closest and farthest vehicles are:" << endl;
	minmax.first->Status(); // should be the 4th vehicle
	minmax.second->Status(); // should be the 2nd to last vehicle
}