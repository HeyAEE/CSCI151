#include <iostream>
#include <cmath>
#include "tempconvert.h"

using namespace std;

double ConvertToFahrenheit(double celsius)
{
	return ((celsius * 9 / 5) + 32);
}

double ConvertToCelsius(double fahrenheit)
{
	return ((fahrenheit - 32) * 5 / 9);
}

double ConvertToFarenheight(double celcius) {
	return ConvertToFahrenheit(celcius);
}

double ConvertToCelcius(double farenheight) {
	return ConvertToCelsius(farenheight);
}

void byvalue() {
	int c = 15;
	int f = 65;

	cout << "Our celsius thermometer measured " << c << " degrees Celsius." << endl;
	cout << "Meanwhile, the Fahrenheit thermometer measured " << f << " degrees Fahrenheit at the same time on the same day." << endl;
	cout << "Are both thermometers functioning properly? Do they give the same temp reading? Let's find out!" << endl;

	cout << f << " degrees Fahrenheit is " << ConvertToCelcius(f) << " degrees Celsius.";
	if (c == ConvertToCelcius(f)) {
		cout << " They're the same temperature. Both thermometers are working perfectly!" << endl;
	}
	else {
		cout << " You should check your thermometer placement. One thermometer is running hot or cold." << endl;
	}

	cout << "This has been a test of the non-emergency temperature gauge system. Please stand by for your regularly scheduled programming." << endl;
}