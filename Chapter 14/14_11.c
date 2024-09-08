#include <stdio.h>
#include <string.h>
#include <math.h>

#define SIZE 10

void transform(double source[], double target[], int n, double (*fp)(double));
double pp1(double source);
double pp2(double source);
double printme(double source[], int size);

int main(void)
{
    double arr1[SIZE];
    double arr2[SIZE];

    for (int i = 0; i<10; i++)
    {
        arr1[i] = (double) i;
    }
    transform(arr1, arr2, SIZE, sin);
    printme(arr2, SIZE);
    transform(arr1, arr2, SIZE, cos);
    printme(arr2, SIZE);
    transform(arr1, arr2, SIZE, pp1);
    printme(arr2, SIZE);
    transform(arr1, arr2, SIZE, pp2);
    printme(arr2, SIZE);
    return 0;
}

void transform(double source[], double target[], int n, double (*fp)(double))
{
    for (int i = 0; i<n; i++)
    {
        target[i] = fp(source[i]);
    }
}

double pp1(double source)
{
    return 2*source;
}
double pp2(double source)
{
    return source - 2.5;
}

double printme(double source[], int size)
{
    for (int i = 0; i<size; i++)
    {
        printf("%lf ", source[i]);
    }
    printf("\n");
}
