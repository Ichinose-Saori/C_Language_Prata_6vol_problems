#include <stdio.h>
#include <string.h>

#define MAIN_TAR 10.0
#define AFT_MAIN 1.5
#define OVERTIME 40
#define FIRTRE 300
#define SECTRE 450
#define PAYFI 0.15
#define PAYSE 0.20
#define PAYTH 0.25

int main()
{
    int hours;
    double sum = 0;
    double sum_before_taxes = 0;
    double after_tax = 0;
    printf("Please, tell us how much hours you've worked!\n");
    scanf("%d", &hours);
    if (hours>40)
    {
        sum+= 40*MAIN_TAR;
        hours-=40;
        sum+= hours*MAIN_TAR*AFT_MAIN;
    }
    else sum+=hours*MAIN_TAR;
    sum_before_taxes += sum;
    if (sum<=FIRTRE)
    {
        after_tax += sum*(1.0-PAYFI);
    }
    else if (sum<=SECTRE)
    {
        after_tax += FIRTRE*(1.0 - PAYFI);
        sum-=FIRTRE;
        after_tax +=sum*(1.0 - PAYSE);
    }
    else
    {
        after_tax += FIRTRE*(1.0 - PAYFI);
        sum-=FIRTRE;
        after_tax += SECTRE*(1.0 - PAYSE);
        sum-=SECTRE-FIRTRE;
        after_tax += sum*(1.0-PAYTH);
    }
    printf("For your %d hours you get %lf before taxes, taxes will be %lf and after tax you get %lf\n.", hours, sum_before_taxes, sum_before_taxes-after_tax, after_tax);

    return 0;
}
