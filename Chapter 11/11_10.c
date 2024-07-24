#define _CRT_SECURE_NO_WARNINGS
#define SIZE 50

#include <stdio.h>

void eraser(char*);
char* s_gets(char*, int);

int main(void)
{
	char arr[SIZE] = "Arr";
	while (s_gets(arr, SIZE, stdin) != NULL && arr[0] != '\0')
	{
		eraser(arr);
		puts(arr);
	}
	return 0;
}

void eraser(char* str)
{
	int i = 0, j = 0;
	while (str[j] != '\0')
	{
		while (str[j] == ' ')
			j++;
		str[i] = str[j];
		i++;
		j++;
	}
	str[i] = '\0';
}

char* s_gets(char* arr, int n)
{
	int i = 0;
	char* ptr;
	ptr = fgets(arr, n, stdin);
	if (ptr)
	{
		while (arr[i] != '\n' && arr[i] != '\0')
			i++;
			if (arr[i] == '\n')
				arr[i] = '\0';
			else
				while (getchar() != '\n')
					continue;
	}
	return ptr;
}
