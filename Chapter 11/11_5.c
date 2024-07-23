#define _CRT_SECURE_NO_WARNINGS
#define SIZE 50 //training array size

#include <stdio.h>

char* strspy(char*, char, int);

int main(void)
{
	char arr[SIZE] = "Louigge#";
	printf("%c and %p\n", *strspy(arr, 'L', SIZE), strspy(arr, 'L', SIZE));
	return 0;
}

char* strspy(char* str, char tar, int n)
{
	int i = 0;
	while (i < n)
	{
		if (*(str + i) == tar)
			return str + i;
		i++;
	}
	return NULL;
}
