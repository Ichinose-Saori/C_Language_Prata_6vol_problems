#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void is_nbit_on(int, int);

int main()
{
    int a, n;
    puts("Enter your number and desired register.");
    scanf("%d", &a);
    scanf("%d", &n);
    is_nbit_on(a, n);
    puts("Program has ended it's work correctly, teeheehee.");
    return 0;
}

void is_nbit_on(int a, int n)
{
    int copy = a;
    int len = 0;
    while (copy>0)
    {
        len++;
        copy >>= 1;
    }
    while (n>len)
    {
        printf("Damn, your number isn't even that big! Try again.\n");
        scanf("%d", &n);
    }
    if (((a >>= (n-1)) & 1) & 1 == 1)
        printf("Yes, it's on!\n");
    else printf("No, it's turned off smh\n");
}
