#define _CRT_SECURE_NO_WARNINGS
#define MAXSIZE 50

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int correct_int(void);
char* s_gets(char*, int);

int main(void)
{
	int words;
	char temp[MAXSIZE];
	printf("How many words do you wish to enter?\n");
	words = correct_int();
	char **arr = (char**) malloc(words * sizeof(char*));
	if (arr == NULL)
	{
		printf("Malloc returned NULL");
		exit(1);
	}
	for (int i = 0; i < words; i++)
		arr[i] = NULL;
	for (int i = 0; i < words; i++)
	{
		if (s_gets(temp, MAXSIZE))
		{
			arr[i] = (char *) malloc((strlen(temp)+1) * sizeof(char));
			if (arr[i] == NULL)
			{
				printf("Malloc returned NULL.\n");
				exit(1);
			}
			for (int j = 0; j < strlen(temp); j++)
			{
				arr[i][j] = temp[j];
			}
			arr[i][strlen(temp)] = '\0';
		}
		else
		{
			printf("Don't ever enter words longer, than %d\n", MAXSIZE);
			exit(1);
		}
	}
	printf("Here we go, have your numbers, lol (core dumped, :) )\n");
	for (int i = 0; i < words; i++)
		puts(arr[i]);
	for (int i = 0; i < words; i++)
		free(arr[i]);
	free(arr);
	return 0;
}

int correct_int(void)
{
	int temp;
	while (scanf("%d", &temp) != 1 && temp < 0)
	{
		while (getchar() != '\n')
			continue;
		printf("We only need positive integers. Now, shall we proceed?\n");
	}
	getchar();
	return temp;
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
