#include <stdio.h>

#define HARMONIC(X,Y) (2.0/((1.0/X) + (1.0/Y)))

int main(void)
{
	printf("%lf\n", HARMONIC(1,4));
	return 0;
}
