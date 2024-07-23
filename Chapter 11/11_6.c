#define _CRT_SECURE_NO_WARNINGS
#define SIZE 50 //training array size

#include <stdio.h>

int is_within(char*, char);

int main(void)
{
	char arr[SIZE] = "Louigge#";
	printf("%d\n", is_within(arr, 'g'));
	return 0;
}

int is_within(char* str, char tar)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (*(str + i) == tar)
			return 1;
		i++;
	}
	return 0;
}
