#include <stdio.h>
#include <ctype.h>

long long fibonacci(int);

int main()
{
    int a;
    while (scanf("%d", &a) == 1)
    {
        printf("%lld\n", fibonacci(a));
    }

    return 0;
}

long long fibonacci(int a)
{
    long long temp;
    if (a == 1 || a==2) return 1;
    long long prev2 = 1, prev1 = 1;
    a-=2;
    while (a>0)
    {
        temp = prev1+prev2;
        prev2 = prev1;
        prev1 = temp;
        a--;
    }
    return temp;
}

