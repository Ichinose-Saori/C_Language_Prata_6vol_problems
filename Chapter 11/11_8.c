//Unfortunately, at this moment I have a lack of algorithmic knowledge
//That's the reason we we will do it dumb way for today.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 50

char* string_in(char*, char*);
char* s_gets(char*, int);

int main(void)
{
	char str[SIZE];
	char find[SIZE];
	char* ptr;
	puts("Enter original and what you want to find(enter empty original to quit):");
	while (s_gets(str, SIZE, stdin) != NULL && s_gets(find, SIZE, stdin) != NULL && str[0]!='\0')
	{
		ptr = string_in(str, find);
		if (ptr)
		{
			printf("%c %p, we found it.\n", *ptr, ptr);
		}
		else printf("Not found.\n");
	}
	return 0;
}

char* string_in(char* orig, char* tar)
{
	int len2 = strlen(tar);
	int len1 = strlen(orig);
	int is_not;

	for (int i = 0; i <= len1 - len2; i++)
	{
		is_not = 0;
		for (int j = 0; j < len2; j++)
		{
			if (orig[i + j] != tar[j])
				is_not = 1;
		}
		if (!is_not)
			return orig + i;
	}
	return NULL;
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
