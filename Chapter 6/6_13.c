#include <stdio.h>

#define SIZE 8

int main()
{
    int arr[SIZE];
    arr[0]=1;
    for (int i = 1; i<SIZE; i++)
    {
        arr[i] = arr[i-1]*2;
    }
    int m=0;
    do {
        printf("%d ",  arr[m]);
        m++;
    } while (m<SIZE);
    printf("\n");
    return 0;
}
