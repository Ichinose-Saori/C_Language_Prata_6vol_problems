#include <stdio.h>
#define SIZE 10

double revert(double *, int size);

int main(void)
{
    double arr[SIZE] = {10.2, 231.4, 32.7};
    revert(arr, SIZE);
    print_arr(arr, SIZE);
    return 0;
}

double revert(double *arr, int size)
{
    double spare;
    double * begin = arr;
    double * end = arr+size-1;
    while(begin<end)
    {
        spare = *begin;
        *begin = *end;
        *end = spare;
        begin++;
        end--;
    }

}

void print_arr(const double *arr, int size)
{
    for (int i = 0; i<size; i++)
        printf("%.1lf ", arr[i]);
    printf("\n");
}
