#include <stdio.h>

int main()
{
    long long downB, upB;
    scanf("%lld", &downB);
    scanf("%lld", &upB);

    for (long long i = downB; i<=upB; i++)
    {
        printf("%lld %lld %lld\n", i, i*i, i*i*i);
    }
    return 0;
}

