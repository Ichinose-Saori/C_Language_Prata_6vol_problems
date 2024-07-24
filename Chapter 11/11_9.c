#define _CRT_SECURE_NO_WARNINGS
#define SIZE 50

#include <stdio.h>

char* s_gets(char* arr, int n);
void turn_180(char*);

int main(void)
{
	char arr[SIZE];
	while (s_gets(arr, SIZE, stdin) != NULL && arr[0] != '\0')
	{
		turn_180(arr);
		puts(arr);
	}
	return 0;
}

void turn_180(char* str)
{
	int len = strlen(str);
	int i = 0, j = len - 1;
	char temp;
	
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

char* s_gets(char* arr, int n)
{
	int i = 0;
	char* ret_val;
	ret_val = fgets(arr, n, stdin);
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
