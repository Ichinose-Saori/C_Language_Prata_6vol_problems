#include <stdio.h>

int main(void)
{
    double a = 2.35;
    scanf("%f", a);
    printf("%.2f\n%.6f\n%e\n%a\n", a, a, a, a);
    return 0;
}