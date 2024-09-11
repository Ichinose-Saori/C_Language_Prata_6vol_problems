#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int rotate(unsigned int a, int n);
int main()
{
    unsigned int a = 1;
    printf("%d\n", rotate(a, 32));
    return 0;
}

int rotate(unsigned int target, int n)
{
    long long mask = 1;
    size_t len = sizeof(target) * 8;
    n = n%len;
    for (int i = 0; i<len-1; i++)
        mask *=2;
    for (int i = 0; i<n; i++)
    {
        if ((target & mask) == mask)
        {
            target <<= 1;
            target += 1;
        }
        else target <<= 1;
    }
    return target;
}
