#include "MyFunctions.h"

bool isEven(int n) {
	return (n % 2 == 0);
}

int addSevenByValue(int n) {
	return n + 7;
}

void addSevenByReference(int& n) {
//Actually CHANGES THE VALUE!
	n = n + 7;
}

/* Why use references instead of passing values?
	If you pass a value, you're copying that value into the new function, increasing memory usage.
	If you pass a REFERENCE, you're using the original value.

	Note: Changes made to the object when passing by reference actually change the original object.
*/