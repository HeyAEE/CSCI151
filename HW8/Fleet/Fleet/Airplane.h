#pragma once
#include "Vehicle.h"
#include <string>
using namespace std;

class Airplane :
	public Vehicle
{
public:
	Airplane(string manString, long serLong);
	virtual ~Airplane();
	void Status() override;
private:
	string man;
	long serial;
};

