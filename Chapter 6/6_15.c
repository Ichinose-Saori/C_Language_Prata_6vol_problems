#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


int main()
{
    char arr[255];
    int len;
    for (int i = 0; i < 255; i++)
    {
        scanf("%c", &arr[i]);
        if (arr[i] == '\n')
        {
            len = i;
            break;
        }
    }
    for (int i = 0; i <= len; i++)
    {
        printf("%c", arr[i]);
    }
    return 0;
}
