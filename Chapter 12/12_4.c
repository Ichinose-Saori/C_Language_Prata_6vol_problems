#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int i_count(void);

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		printf("I was called %d times.\n", i_count());
	}
	return 0;
}

int i_count(void)
{
	static n = 0;
	n++;
	return n;
}
