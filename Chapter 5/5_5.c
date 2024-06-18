#include <stdio.h>

#define HOUOUIN "EL PSY CONGROO!"

int main()
{
    int count, sum;
    int lim;
    printf("Please, specify the number you want to count for!\n");
    scanf("%d", &lim);
    count = sum = 0;
    while(count++<lim)
    {
        sum = sum+count;
    }
    printf("sum = %d\n", sum);
    return 0;
}

//YES, I'M FULLY AWARE THAT THERE IS O(1) SOLUTION FOR EVERY N BY FORMULA.
