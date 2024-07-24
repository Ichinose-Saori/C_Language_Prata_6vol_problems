#define _CRT_SECURE_NO_WARNINGS
#define SIZE 50

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* s_gets(char* a, int num);
void mathematician(char*);

int main()
{
	char* arr[SIZE];
	while (s_gets(arr, SIZE, stdin) != NULL)
	{
		mathematician(arr);
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

void mathematician(char* arr)
{
	int i = 0;
	int in_w = 0;
	int words = 0, upper = 0, lower = 0, punct = 0, digits = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] != ' ' && arr[i] != '\t' && in_w == 0)
		{
			in_w = 1;
		}
		else if ((in_w == 1) && (arr[i] == ' ' || arr[i] == '\t'))
		{
			in_w = 0;
			words++;
		}
		if (isdigit(arr[i])) digits++;
		else if (ispunct(arr[i])) punct++;
		else if (isupper(arr[i])) upper++;
		else if (islower(arr[i])) lower++;
		i++;
	}
	if (in_w == 1) words++;
	printf("There were %d words, %d lower letters, %d upper letters, %d punctuation signs and %d digits.\n", words, lower, upper, punct, digits);
}
