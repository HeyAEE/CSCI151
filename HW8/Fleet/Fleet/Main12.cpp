#include "Boat.h"
#include "Airplane.h"
#include "Car.h"
#include <vector>

// Problem 1
//int main()
//{
//	Car car{ "Tesla", "S", 12345L };
//	Boat boat{ "Mayflower", 7.5 };
//	Airplane plane{ "Boeing", 98765L };
//	// (should print) Car: Make - Tesla, Model - S, VIN - 12345
//	car.Status();
//	// (should print) Boat: Name - Mayflower, Cargo - 7.5
//	boat.Status();
//	// (should print) Airplane: Manufacturer - Boeing, Serial - 98765
//	plane.Status();
//}

// Problem 2
//int main()
//{
//	Car car{ "Tesla", "S", 12345L };
//	Boat boat{ "Mayflower", 7.5 };
//	Airplane plane{ "Boeing", 98765L };
//	car.SendToLocation(pair<double, double>(1.0, 3.5));
//	// (should print) Car: Location - (1.0, 3.5), Make - Tesla, Model - S, VIN 	-12345
//	car.Status();
//	boat.SendToLocation(pair<double, double>(1.1, 3.4));
//	// (should print) Boat: Location - (1.1, 3.4), Name - Mayflower, Cargo - 7.5
//	boat.Status();
//	plane.SendToLocation(pair<double, double>(0.0, -3.5));
//	// (should print) Airplane: Location - (0.0, -3.5), Manufacturer - Boeing, Serial - 98765
//	plane.Status();
//}