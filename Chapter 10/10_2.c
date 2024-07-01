#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5


void copy_arr(double *, const double *, int);
void copy_ptr(double *, const double *, int);
void copy_ptrs(double *, const double *, int*);
void printo_arr(const double *, int);

int main(void)
{
    double source[SIZE] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    double target1[SIZE];
    double target2[SIZE];
    double target3[SIZE];

    copy_arr(target1, source, SIZE);
    printo_arr(target1, SIZE);
    copy_ptr(target2, source, SIZE);
    printo_arr(target2, SIZE);
    copy_ptrs(target3, source, target3 + SIZE);
    printo_arr(target3, SIZE);

    return 0;
}

void copy_arr(double *target, const double *source, int len)
{
    for (int i = 0; i < len; i++)
    {
        target[i] = source[i];
    }
}

void copy_ptr(double *target, const double* source, int len)
{
    for (int i = 0; i < len; i++)
    {
        *(target + i) = *(source + i);
    }
}

void copy_ptrs(double* start, const double* source, double* end)
{
    while (start < end)
    {
        *start = *source;
        start++;
        source++;
    }
}

void printo_arr(const double* target, int len)
{
    for (int i = 0; i < len; i++) printf("%lf ", *(target + i));
    printf("\n");
}
