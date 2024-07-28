#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "pe12-2a.h"

int main(void)
{
	int mode, path, prevmode = 0;
	double fuel;

	printf("Enter 0 for metric and 1 for american modes: \n");
	scanf("%d", &mode);
	while (mode >= 0)
	{
		set_mode(&prevmode, &mode);
		get_info(mode, &path, &fuel);
		show_info(mode, path, fuel);
		printf("Enter 0 for metric and 1 for american modes: \n");
		printf("-1 to end this all.\n");
		scanf("%d", &mode);
	}
	printf("Program has ended.\n");
	return 0;
}
