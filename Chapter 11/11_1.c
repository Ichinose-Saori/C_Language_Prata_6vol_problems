#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 5

void grave_danger(char*, int);

int main(void)
{
	int arr[SIZE+1];
	grave_danger(arr, SIZE);
	fputs(arr, stdout);
	return 0;
}

void grave_danger(char* arr, int n)
{
	int i = 0; 
	while (i < n)
	{
		arr[i] = getchar();
		i++;
	}
	arr[n] = '\0';
}
