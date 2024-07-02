#include <stdio.h>
#define SIZE 10

int big_index(const double *, int);

int main(void)
{
    double arr[SIZE] = {1.2, -12123.3, -43.0};
    printf("The index of biggest value is %d.\n", big_index(arr, SIZE));
    return 0;
}

int big_index(const double * arr, int len)
{
    double big = arr[0];
    int index = 0;
    for (int i = 0; i<len; i++)
    {
        if (arr[i]>big)
        {
            big = arr[i];
            index = i;
        }
    }
    return index;
}
