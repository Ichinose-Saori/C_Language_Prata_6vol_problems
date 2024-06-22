#include <stdio.h>

#define SIZE 8

int main()
{
    int arr[SIZE];
    printf("Please, enter ONLY INTEGER values, I don't want to make this program foolproof :(\n");
    for (int i = 0; i<SIZE; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = SIZE-1; i>=0; i--)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
