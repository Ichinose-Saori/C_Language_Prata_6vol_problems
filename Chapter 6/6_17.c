#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


int main()
{
    double sum_m = 1000000;
    int years = 0;
    while (sum_m>0)
    {
        sum_m -= 100000;
        sum_m*=1.08;
        years++;
    }
    printf("%d years will pass\n", years);
    return 0;
}
