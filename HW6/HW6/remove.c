#include <stdlib.h>
#include <stdio.h>

void insert(const int* from, int* to, int value, size_t location, size_t
	toLength)
{
	int fromIndex = 0;
	for (int toIndex = 0; toIndex < toLength; ++toIndex)
	{
		if (toIndex != location)
		{
			to[toIndex] = from[fromIndex];
			++fromIndex;
		}
		else
		{
			to[toIndex] = value;
		}
	}
}

void removevalue(const int* from, int* to, size_t location, size_t fromLength)
{
	int toIndex = 0;
	for (int fromIndex = 0; fromIndex < fromLength; ++fromIndex) {
		if (fromIndex != location) {
			to[toIndex] = from[fromIndex];
			++toIndex;
		}
		else {
			printf("Skipping! Do a happy dance."); //skip over the copying. When this happens, fromIndex should be greater than toIndex reflecting that a value has been skipped.
		}
	}
}

int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int arr2[6];
	insert(arr, arr2, 15, 5, 6);
	printf(arr2);
	int arr3[5];
	removevalue(arr2, arr3, 3, 6);
	printf(arr3);
}