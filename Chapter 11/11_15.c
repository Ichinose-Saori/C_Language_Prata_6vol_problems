#define _CRT_SECURE_NO_WARNINGS

#define SIZE 10

#include <stdio.h>
#include <ctype.h>

int there_is_nondigit(char*);

int main(int argc, char* argv[])
{
	char arr[SIZE] = "123sad1";
	printf("%d\n", there_is_nondigit(arr));
	return 0;
}

int there_is_nondigit(char* arr)
{
	int i = 0;
	while (arr[i] != '\0')
	{
		if (isdigit(arr[i])==0)
			return 1;
		i++;
	}
	return 0;
}
