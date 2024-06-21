#include <stdio.h>

int main()
{
    char car = 'A';
    for (int i = 0; i<6; i++)
    {
        for (int j = 0; j<=i; j++)
        {
            printf("%c", car);
            car++;
        }
        printf("\n");
    }
    return 0;
}

