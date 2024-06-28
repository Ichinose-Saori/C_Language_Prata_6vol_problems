#include <stdio.h>

void chline(char, int, int);
void swap_to_b(int *, int *);

int main()
{
    char ch;
    int a, b;
    printf("Please, enter you character!\n");
    scanf("%c", &ch);
    printf("Please, enter your numbers!\n");
    scanf("%d %d", &a, &b);
    chline(ch, a, b);
    return 0;
}

void chline(char ch, int a, int b)
{
    swap_to_b(&a, &b);
    for (int i = 0; i<a; i++)
    {
        putchar(' ');
    }
    for (int i = a; i<=b; i++)
    {
        putchar(ch);
    }
    putchar('\n');
}

void swap_to_b(int * a, int * b)
{
    if (a>b)
    {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

//Yes, it's UNSAFE but from now on I will assume that USER enters correctly all of his data, because checking it for being correct TAKES MUCH LONGER than writing program's base
