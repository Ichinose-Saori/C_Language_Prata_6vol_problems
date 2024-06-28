#include <stdio.h>
#include <ctype.h>

double power (double, double);

int main()
{
    printf("%lf\n", power(0, -1));
    return 0;
}

double power(double n, double p)
{
    double pow = 1;
    if (p>0)
    {
        for (int i = 1; i<=p; i++)
        pow*=n;
    }
    else if (p == 0)
    {
        if (n == 0)
        {
            printf("0 in power of 0 is undefined, so result is ");
            return 1;
        }
        return 1;
    }
    else
    {
        if (n == 0) return 0;
        for (int i = 1; i<= -p; i++)
        {
            pow*= (double)1/n;
        }
    }
    return pow;
}
