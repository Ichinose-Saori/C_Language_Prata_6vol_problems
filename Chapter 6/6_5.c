#include <stdio.h>

#define NEED 5

int main()
{
    for (int i = 0; i<NEED; i++)
    {
        char temp = 'A';
        for (int j = 0; j<NEED-i-1; j++)
            printf(" ");
        for (int j = 0; j<=i; j++)
        {
            printf("%c", temp++);
        }
        temp--;
        temp--;
        for (int j = 0; j<=i-1; j++)
        {
            printf("%c", temp--);
        }
        printf("\n");
    }
    return 0;
}

