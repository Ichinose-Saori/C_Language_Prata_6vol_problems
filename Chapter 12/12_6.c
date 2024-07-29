#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10
#define CYCLES 1000

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	srand(time(0));
	int arr[SIZE + 1] = { 0 };
	for (int i = 0; i < CYCLES; i++)
		arr[rand() % SIZE + 1]++;
	for (int i = 1; i < SIZE + 1; i++)
	{
		printf("%d is met %d times.\n", i, arr[i]);
	}
	return 0;
}
