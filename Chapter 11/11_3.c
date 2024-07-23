#define _CRT_SECURE_NO_WARNINGS
#define SIZE 50

#include <stdio.h>

void word(char*);

int main(void)
{
	int arr[SIZE+1];
	word(arr);
	puts(arr);
	return 0;
}

void word(char* arr)
{
	int i = 0;
	int started = 0;
	char a;
	while ((a = getchar()) == ' ' || a == '\n' || a == '\t') 
		continue;
	arr[i] = a;
	i++;
	while (i < SIZE)
	{
		arr[i] = getchar();
		if (arr[i] == ' ' || arr[i] == '\n' || arr[i] == '\t')
		{
			arr[i] = '\0';
			return;
		}
		i++;
	}
	arr[SIZE] = '\0';
}
