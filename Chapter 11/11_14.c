#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	//double a = 2.23;
	//int n = -10;
	double a = atof(argv[1]);
	double tar = 1;
	int n = atoi(argv[2]);
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
			tar *= a;
	}
	else if (n == 0) tar = 1.0;
	else
	{
		for (int i = 0; i < -n; i++)
		{
			tar /= a;
		}
	}
	printf("%lf\n", tar);

	return 0;
}
