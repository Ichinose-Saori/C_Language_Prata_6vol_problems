#include <stdio.h>

#define SIZE 8

int main()
{
    printf("This program calculates two sums. To do that, please, enter amount of summing matter!\n");
    printf("To stop, enter number less than or equal to zero.\n");
    int amount;
    double sumA = 0, sumB = 0;
    while (scanf("%d", &amount) && amount>0)
    {
        sumA = 0;
        sumB = 0;
        double denom = 1.0;
        for (int i = 0; i<amount; i++)
        {
            sumA +=1.0/denom;
            if(i%2 == 0) sumB+=1.0/denom;
            else sumB-=1.0/denom;
            denom+=1.0;
        }
        printf ("Sum A = %lf and sum B = %lf\n", sumA, sumB);
    }
    return 0;
}
