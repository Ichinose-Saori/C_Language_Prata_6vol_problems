#define _CRT_SECURE_NO_WARNINGS
#define SIZE 100

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	srand(time(0));
	int arr[SIZE];
	int temp;

	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 10+1;
	}
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = i + 1; j < SIZE; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	for (int i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	return 0;
}
