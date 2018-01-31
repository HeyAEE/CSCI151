#include <stdio.h>
#include <iostream>
#pragma warning(disable : 4700) //Not standard C++; specific to VS compiler; tells VS to ignore error code 4700

using namespace std; //shortcut to say "Hey, I'm interested in that namespace."

int global = 5;

void task() {
	int taskLocal = 2;
}


/* int main() {
	// What's inside of the function block is in the stack frame.
	int local = 3;

	//printf("taskLocal: %d\n", taskLocal)
	//printf("global: %d\n", global);
	//printf("local: %d\n", local);

	cout << "local: " << local << endl;
	cout << "global: " << global << endl;

	if (local > 5) {
		cout << "greater than 5" << endl;
	}
	else if (local == 5) {
		cout << "equal to 5" << endl;
	}
	else {
		cout << "less than or equal to 5" << endl;
	}
} */

int main() {
	int8_t index = 0;

	for (int8_t i = 0; i < 10; i++) {
		cout << "Hello #" << (int)i << endl;
		index = i;
	}

	cout << "Index is now " << (int)index << endl;
}