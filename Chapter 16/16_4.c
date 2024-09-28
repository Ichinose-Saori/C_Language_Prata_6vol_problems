#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>

int main(void)
{
	double LZ;
	scanf("%lf", &LZ);
	clock_t time0 = clock();
	while (((clock() - time0) / CLOCKS_PER_SEC) < LZ)
	{
		printf("WE LOVE LZ!\n");
	}
	return 0;
}
