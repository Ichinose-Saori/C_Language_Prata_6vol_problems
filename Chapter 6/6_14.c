#include <stdio.h>

#define SIZE 8

int main()
{
    double arr1[SIZE];
    double arr2[SIZE];

    scanf("%lf", &arr1[0]);
    arr2[0] = arr1[0];

    for (int i = 1; i<SIZE; i++)
    {
        scanf("%lf", &arr1[i]);
        arr2[i]=arr1[i]+arr2[i-1];
    }
    for (int i = 0; i<SIZE; i++)
    {
        printf("%8.2lf ", arr1[i]);
    }
    printf("\n");
    for (int i = 0; i<SIZE; i++)
    {
        printf("%8.2lf ", arr2[i]);
    }
    return 0;
}
