#include <iostream>
#include <cmath>
#include "tempconvert.h"

using namespace std;

void ConvertToFahrenheitR(double& celsius)
{
	celsius = (celsius * 9 / 5) + 32;
}

void ConvertToCelsiusR(double& fahrenheit)
{
	fahrenheit = (fahrenheit - 32) * 5 / 9;
}

void ConvertToFarenheightR(double& celcius) {
	ConvertToFahrenheitR(celcius);
}

void ConvertToCelciusR(double& farenheight) {
	ConvertToCelsiusR(farenheight);
}

void byreference() {
	double c = 15;
	double f = 65;

	cout << "Our celsius thermometer measured " << c << " degrees Celsius." << endl;
	cout << "Meanwhile, the Fahrenheit thermometer measured " << f << " degrees Fahrenheit at the same time on the same day." << endl;
	cout << "Are both thermometers functioning properly? Do they give the same temp reading? Let's find out!" << endl;

	cout << f << " degrees Fahrenheit is ";
	ConvertToCelciusR(f);
	cout << f << " degrees Celsius.";
	if (c == f) {
		cout << " They're the same temperature. Both thermometers are working perfectly!" << endl;
	}
	else {
		cout << " You should check your thermometer placement. One thermometer is running hot or cold." << endl;
	}

	cout << "This has been a test of the non-emergency temperature gauge system. Please stand by for your regularly scheduled programming." << endl;
}