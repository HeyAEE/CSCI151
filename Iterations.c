#include <stdio.h>

#define MAX_ITERATIONS 1024

void main() {
	int x = 12345;
	
	while (x<MAX_ITERATIONS) {
		printf("Iterate");
	}
	
	if (x > 0) {
		printf("The value %d is positive\n", x);
	}
	
	if (x % 2 == 0) {
		printf("the value is also even\n");
	}
}