#include <stdio.h>
#include <string.h>

double absol(double a, double b); //abs() function from math.h
void manip(double a, double b);

int main()
{
    double a, b;
    printf("Please, enter two \"DOUBLE\" type numbers!\n");
    printf("To exit, enter q.\n");
    while (scanf("%lf", &a) && scanf("%lf", &b))
    {
        manip(a, b);
    }
    return 0;
}

double absol(double a, double b)
{
    if (a>b) return a-b;
    return b-a;
}
void manip(double a, double b)
{
    if (a==0 || b == 0)
    {
            printf("Ehh, zero numbers are prohibited, try again!\n");
    }
    else printf("%lf\n", absol(a, b)/(a*b));
}
