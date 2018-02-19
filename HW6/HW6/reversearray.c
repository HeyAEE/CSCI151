#include <stdio.h>
void reverse(int* values, size_t size)
{
	int temp = (values)[0];
	int i = 0;
	int j = size - 1;
	while (i < j) {
		temp = values[i];
		values[i] = values[j];
		values[j] = temp;
		i++;
		j--;
	}
}
int main()
{
	const int SIZE = 10;
	int values[] = { 5, 4, 3, 2, 1, 10, 9, 8, 7, 6 };
	for (int i = 0; i < SIZE; ++i)
	{
		printf("Value: %d\t", values[i]);
	}
	printf("\n");
	reverse(values, SIZE);
	for (int i = 0; i < SIZE; ++i)
	{
		printf("Reversed: %d\t", values[i]);
	}
	printf("\n");
}