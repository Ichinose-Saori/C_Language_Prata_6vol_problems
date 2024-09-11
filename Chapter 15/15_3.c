#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int bits_on(int);

int main()
{
    int a;
    puts("Enter your number, pls QAQ");
    scanf("%d", &a);
    printf("%d bits are turned on.\n", bits_on(a));
    return 0;
}

int bits_on(int a)
{
    int ans = 0;
    while (a>0)
    {
        if ((a & 1) == 1)
            ans++;
            a >>= 1;
    }
    return ans;
}
