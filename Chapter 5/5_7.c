#include <stdio.h>

#define HOUOUIN "EL PSY CONGROO!

double cube_it (double n);

int main()
{
    double test_subj1;
    printf("Please, proceed to enter a number in DBL format.\n");
    scanf("%lf", &test_subj1);
    printf("The cube of your ******** number is %lf", cube_it(test_subj1));
    return 0;
}

double cube_it (double n)
{
    return n*n*n;
}
