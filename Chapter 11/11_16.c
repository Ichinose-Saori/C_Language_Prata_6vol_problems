#define _CRT_SECURE_NO_WARNINGS

#define SIZE 50

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* s_gets(char* arr, int num);
void transform(char* arr, int mode);

int main(int argc, char* argv[])
{
	char arr[SIZE];
	int mode=1;
	if (argc == 1) mode = 1;
	else if (strcmp(argv[1], "-p") == 0) mode = 1;
	else if (strcmp(argv[1], "-u") == 0) mode = 2;
	else if (strcmp(argv[1], "-l") == 0) mode = 3;
	printf("%d\n", mode);
	while (s_gets(arr, SIZE) != NULL)
	{
		transform(arr, mode);
	}
	return 0;
}

char* s_gets(char* arr, int num)
{
	int i = 0;
	char* ret_val;
	ret_val = fgets(arr, num, stdin);
	if (ret_val)
	{
		while (arr[i] != '\n' && arr[i] != '\0')
			i++;
		if (arr[i] == '\n')
			arr[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

void transform(char* arr, int mode)
{
	int n = strlen(arr);
	if (mode == 2)
	{
		for (int i = 0; i < n; i++)
		{
			if (islower(arr[i]))
				arr[i] = toupper(arr[i]);
		}
	}
	else if (mode == 3)
	{
		for (int i = 0; i < n; i++)
		{
			if (isupper(arr[i]))
				arr[i] = tolower(arr[i]);
		}
	}
	puts(arr);
}
