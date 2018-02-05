#include <stdio.h>
#pragma warning(disable : 4700) //Not standard C++; specific to VS compiler; tells VS to ignore error code 4700

int global;

void task() {
	int taskLocal;
}


int main() {
// What's inside of the function block is in the stack frame.
	int local;

	//printf("taskLocal: %d\n", taskLocal)
	printf("global: %d\n", global);
	printf("local: %d\n", local);
}
