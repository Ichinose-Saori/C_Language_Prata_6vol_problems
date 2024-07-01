#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 10

int biggest_in_arr(const int *, int sizee);

int main(void)
{
    int arr[SIZE] = { 10, 12312, 1231, 323332, -12323, 124, 54323, 334, 0, 0};
    printf("%d\n", biggest_in_arr(arr, SIZE));
    return 0;
}

int biggest_in_arr(const int * arr, int sizee)
{
    int big = arr[0];
    for (int i = 0; i < sizee; i++)
    {
        if (arr[i] > big) big = arr[i];
    }
    return big;
}
