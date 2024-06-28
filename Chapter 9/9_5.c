#include <stdio.h>

void larger_of(double *, double *);

int main()
{
    double a, b;
    printf("Please, enter two numbers.\n");
    scanf("%lf %lf", &a, &b);
    larger_of(&a, &b);
    printf("%lf %lf", a, b);
    return 0;
}

void larger_of(double *a, double *b)
{
    if (*a > *b) *b = *a;
    else *a = *b;
}
