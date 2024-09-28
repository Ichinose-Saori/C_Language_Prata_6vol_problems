#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

struct polarka {
	double r;
	double phi;
};

int main(void)
{
	struct polarka obh;
	scanf("%lf", &obh.r);
	scanf("%lf", &obh.phi);
	
	printf("X = %lf\n", obh.r * cos(obh.phi));
	printf("Y = %lf\n", obh.r * sin(obh.phi));
  
	return 0;
}
