#include <stdio.h>
#include <ctype.h>

void to_base_n(int, int);

int main()
{
    to_base_n(100, 8);
    return 0;
}

void to_base_n(int a, int base)
{
    if(a>=base)
        to_base_n(a/base, base);
    printf("%d", a%base);
}

