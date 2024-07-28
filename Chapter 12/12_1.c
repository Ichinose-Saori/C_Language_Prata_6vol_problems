#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void critic(void);

int main(void)
{
	int units;
	printf("How much pounds is in oil barrel?\n");
	scanf("%d", &units);
	while (units != 56)
	{
		critic();
		scanf("%d", &units);
	}
	printf("You knew it!\n");
	return 0;
}

void critic(void)
{
	printf("Better luck next time! Try again.\n");
}
