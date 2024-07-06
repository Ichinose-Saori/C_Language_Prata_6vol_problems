#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

char* grave_danger(int, char*);

int main(void)
{
    char arr[SIZE+1];
    grave_danger(SIZE, arr);
    fputs(arr, stdout);
    return 0;
}

char* grave_danger(int n, char* arr)
{
    fgets(arr, n, stdin);
    return arr;
}
