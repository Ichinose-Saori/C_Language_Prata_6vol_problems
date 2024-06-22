#include <stdio.h>
#include <string.h>

void exercise();
long long sum_of_squares(long long a, long long b);

int main()
{
    exercise();
    return 0;
}

void exercise()
{
    printf("Please, enter lower and upper border for your sum!\n");
    printf("To exit the program, enter upper border to be lower than first number.\n");
    long long a, b;
    long long sum = 0;
    while(scanf("%lld", &a) && scanf("%lld", &b))
    {
        if (a<b)
        {
            if (a>0 && b>0)
            {
                printf("The sum of squares from %lld to %lld is %lld\n", a*a, b*b, sum_of_squares(a, b));
            }
            else
            {
                printf("Well, you see, to do it as intended is not possible,\n"
                        "because square of negative number is quite positive, so let's do it other way!\n");
                printf("The sum of squares from %lld to %lld is %lld\n", a, b, sum_of_squares(a, b));
            }
        }
        else break;
    }
    printf("We are done!\n");
}

long long sum_of_squares(long long a, long long b)
{
    if (a<0 && b<0)
    {
        return sum_of_squares(-b, -a);
    }
    else if (a<0 && b>0)
    {
        return sum_of_squares(1, -a)+sum_of_squares(1, b);
    }
    else
    {
        return (b*(b+1)*(2*b+1))/6-((a-1)*(a)*(2*a - 1))/6;
    }
}
