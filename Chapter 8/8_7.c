#include <stdio.h>
#include <string.h>

//#define MAIN_TAR 10.0
#define AFT_MAIN 1.5
#define OVERTIME 40
#define FIRTRE 300
#define SECTRE 450
#define PAYFI 0.15
#define PAYSE 0.20
#define PAYTH 0.25

char corr_char(void);
int corr_int(void);

int main()
{
    char option;
    double MAIN_TAR;
    printf("Please, enter a number representing options listed below!\n");
    printf("m) $8,75/h\n");
    printf("n) $9,33/h\n");
    printf("o) $10,00/h\n");
    printf("p) $11,20/h\n");
    printf("q) Exit\n");
   /* if (scanf("%d", &option) != 1){
            printf("Great, non-integer value! The program is dead.\n");
            return -1;
    }*/
    option = corr_char();
    while (option!='q')
    {
       /* while (option<1 ||option>5)
        {
            printf("Please, choose properly!\n");
             if (scanf("%d", &option) != 1){
            printf("Great, non-integer value! The program is dead.\n");
            return -1;
    }
        }*/
        switch(option)
        {
        case 'a':
            MAIN_TAR = 8.75;
            break;
        case 'b':
            MAIN_TAR = 9.33;
            break;
        case 'c':
            MAIN_TAR = 10.00;
            break;
        case 'd':
            MAIN_TAR = 11.20;
            break;
        }
        int hours;
        double sum = 0;
        double sum_before_taxes = 0;
        double after_tax = 0;
        printf("Please, tell us how much hours you've worked!\n");
        hours = corr_int();
        if (hours>OVERTIME)
        {
            sum+= OVERTIME*MAIN_TAR;
            hours-=OVERTIME;
            sum+= hours*MAIN_TAR*AFT_MAIN;
        }
        else sum+=(double)hours*MAIN_TAR;
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
        printf("For your %d hours you get %lf before taxes, taxes will be %lf and after tax you get %lf.\n\n", hours, sum_before_taxes, sum_before_taxes-after_tax, after_tax);
        printf("Please, enter a number representing options listed below!\n");
        printf("a) $8,75/h\n");
        printf("b) $9,33/h\n");
        printf("c) $10,00/h\n");
        printf("d) $11,20/h\n");
        printf("e) Exit\n");
       /* if (scanf("%d", &option) != 1){
            printf("Great, non-integer value! The program is dead");
            return -1;
        }*/
        option = corr_char();
    }

    return 0;
}

char corr_char(void)
{
    char ch;
    while ((ch = getchar())<'m' || ch > 'q') continue;
    return ch;
}

int corr_int(void)
{
    int target=-5;
    while((scanf("%d", &target)!=1))
    {
        getchar();
        printf("Please, n>=0 and integer\n");
        continue;
    }
    while(target<0)
    {
        printf("Please, >=0\n");
    while((scanf("%d", &target)!=1))
    {
        getchar();
        printf("Please, n>=0 and integer\n");
        continue;
    }
    }
    return target;
}
