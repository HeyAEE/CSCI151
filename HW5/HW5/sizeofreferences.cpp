#pragma once

#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

void size(string t, int length) {
	cout << "Size of " << t << ": " << length << endl;
}

int sizeofreferences() {
	int eger;
	float ingpoint;
	string chararray;
	double trouble;
	char acter;
	bool ean;
	long ervalue;

	size(typeid(&eger).name(), sizeof(&eger));
	size(typeid(&ingpoint).name(), sizeof(&ingpoint));
	size(typeid(&chararray).name(), sizeof(&chararray));
	size(typeid(&trouble).name(), sizeof(&trouble));
	size(typeid(&acter).name(), sizeof(&acter));
	size(typeid(&ean).name(), sizeof(&ean));
	size(typeid(&ervalue).name(), sizeof(&ervalue));
	return 1;
}