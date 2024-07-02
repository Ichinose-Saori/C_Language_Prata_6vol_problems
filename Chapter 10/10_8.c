#include <stdio.h>

void copy_arr(double *, const double *, int);

int main(void)
{
    double arr7[7] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    double arr3[3];
    copy_arr(arr3, arr7+2, 3);
    for (int i = 0; i<3; i++) printf("%lf ", arr3[i]);
    printf("\n");
    return 0;
}

void copy_arr(double *target, const double *source, int len)
{
    for (int i = 0; i < len; i++)
    {
        target[i] = source[i];
    }
}
