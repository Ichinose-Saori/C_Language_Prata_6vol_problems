#include <stdio.h>

#define LETTERS 26

void Temperatures(double FahrTem);

int main()
{
    char alpha[LETTERS];
    for (int i = 0; i<LETTERS; i++)
    {
        alpha[i] = 'A' + i;
    }
    for (int i = 0; i<LETTERS; i++)
    {
        printf("%c\n", alpha[i]);
    }
    return 0;
}

