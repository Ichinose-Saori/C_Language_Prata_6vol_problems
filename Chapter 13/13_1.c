#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSZ 80

char* s_gets(char*, int size);

int main(void)
{
	int ch;
	FILE* fp;
	unsigned long count = 0;
	char path[MAXSZ];
	if (s_gets(path, MAXSZ - 1) == NULL)
	{
		printf("Failed to read a string");
	}
	if ((fp = fopen(path, "r")) == NULL)
	{
		printf("Failed to open file.\n");
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("File %s contains %lu symbols\n", path, count);
	return 0;
}

char* s_gets(char* arr, int size)
{
	char* ret_val;
	char* find;
	ret_val = fgets(arr, size, stdin);
	if (ret_val)
	{
		find = strchr(arr, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
