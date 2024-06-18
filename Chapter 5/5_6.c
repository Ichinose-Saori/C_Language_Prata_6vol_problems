#include <stdio.h>

#define HOUOUIN "EL PSY CONGROO!"

int square(int n);

int main()
{
    int count, sum;
    int lim;
    printf("Please, specify the number you want to count for!\n");
    scanf("%d", &lim);
    count = sum = 0;
    while(count++<lim)
    {
        sum = sum+square(count);
    }
    printf("sum = %d\n", sum);
    return 0;
}

int square (int n)
{
    return n*n;
}

//YES, I'M FULLY AWARE THAT THERE IS STILL O(1) SOLUTION FOR EVERY N BY FORMULA, BUT IT IS A BIT MORE COMPLICATED THAN IN 5_5.
