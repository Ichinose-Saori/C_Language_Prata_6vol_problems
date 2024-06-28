#include <stdio.h>

double minm(double, double);

int main()
{
    printf("%lf\n", minm(5.0, 4.0));
    return 0;
}

double minm(double m, double n)
{
    return(m<n ? m : n);
}
