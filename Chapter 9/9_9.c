#include <stdio.h>
#include <ctype.h>

double power (double, int);
double power_pos(double, int);

int main()
{
    printf("%lf\n", power(2, -3));
    return 0;
}

double power(double n, int p)
{
    if (n == 0)
    {
        if (p ==0) return 1;
        return 0;
    }
    if (p>0) return power_pos(n, p);
    if (p<0)
    {
        if (p ==0)
        { printf("Undefined. Error!\n");
        return -1;
        }
        return 1/power_pos(n, -p);
    }
}

double power_pos(double n, int p)
{
    if (p ==0) return 1;
    return n*power_pos(n, p-1);
}
