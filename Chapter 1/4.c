#include <stdio.h>

void jolly(void);
void deny(void);

int main(void)
{
	jolly();
	jolly();
	jolly();
	deny();
	return 0;
}

void jolly(void)
{
	printf("He is funny guy!\n");
}

void deny(void)
{
	printf("And no one can deny it!\n");
}


