#include <stdio.h>

void sort_var(double *, double *, double *);
double swapp(double *, double *);

int main()
{
    double a = 50.0, b = -1.0, c = -105.0;
    sort_var(&c, &b, &a);
    printf("%lf %lf %lf", a, b, c);
    return 0;
}

void sort_var(double * a, double * b, double * c)
{

    if (*a > *b && *a > *c)
    {
        if (*c > *b)
        {
            swapp(b, c);
        }
    }
    else if (*b > *a && *b > *c)
    {
        if (*a > *c)
        {
            swapp(a, b);
        }
        else
        {
            swapp(b, a);
            swapp(a, c);
        }
    }
    else
    {
        if (*a > *b)
        {
            swapp(c, a);
            swapp(a, b);
        }
        else swapp(c, a);
    }
}

double swapp(double *a, double *b)
{
    double temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
