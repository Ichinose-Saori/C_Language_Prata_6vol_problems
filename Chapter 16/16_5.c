#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void lottery(const int arr[], int size, int tries);

int main()
{
    srand(time(NULL));
    int arr[SIZE];
    int ZerLu;
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand();
    }
    printf("Hello!!!!\nHow many positions do you want to roll?\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &ZerLu);
        printf("NOW FOR REAL\n");
        lottery(arr, SIZE, ZerLu);
    }
    return 0;
}

void lottery(const int arr[], int size, int tries)
{
    srand(time(NULL));
    int dice;
    if (tries > size)
        tries = size;
    int* ptr = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        ptr[i] = 0;
    }
   
    for (int i = 0; i < tries; i++)
    {
        dice = rand() % size;
        int j = dice;
        while (ptr[j] != 0)
        {
                j++;
                j %= size;
        }
        printf("%d\n", arr[j]);
        ptr[j] = 1;
    }
    free(ptr);
}
