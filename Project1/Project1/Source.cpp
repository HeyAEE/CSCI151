#include <iostream>
#include <string>

#include "MyFunctions.h"

using namespace std;

/* Crash course to C++

Example function: void sayHello()
*/

void sayHello(/*The list of arguments*/string name/*looking for a string whose variable will be "name"*/) {
	cout << "Hello, " << name << endl;
}

void increaseInfo(int n) {
	bool result = isEven(n);
	if (result) {
		cout << "The number " << n << " is even." << endl;
	}
	else {
		cout << "The number " << n << " is odd." << endl;
	}

}

int main() {
	sayHello("A-bomb");

	int n = 127;

	increaseInfo(n);
	addSevenByValue(n);
	increaseInfo(n);
	addSevenByReference(n);
	increaseInfo(n);
}

/* We can declare a function without defining it. Just have to declare it early.
	Alternately, we can declare a function in the header.
*/