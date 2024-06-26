#include <stdio.h>

void binary_calculator(void);
void start_message(void);
char correct_char(void);
double correct_double(void);

int main()
{
    binary_calculator();
    return 0;
}

void binary_calculator(void)
{
    char selector;
    double a, b;
    start_message();
    selector = correct_char();
    while (selector != 'e')
    {
        printf("Enter first number:\n");
        a = correct_double();
        printf("Enter second number:\n");
        b = correct_double();
        switch(selector)
        {
        case 'a':
            printf("%lf + %lf = %lf\n",a , b, a+b);
            break;
        case 'b':
            printf("%lf - %lf = %lf\n", a, b, a-b);
            break;
        case 'c':
            printf("%lf * %lf = %lf\n", a, b, a*b);
            break;
        case 'd':
            while (b==0)
            {
                printf("Please, B can't be 0\n");
                b = correct_double();
            }
            printf("%lf / %lf = %lf\n", a, b, a/b);
            break;
        }
        start_message();
        selector = correct_char();
    }
}

void start_message(void)
{
    printf("Please, choose your operator:\n");
    printf("a) Addition\n");
    printf("b) Difference\n");
    printf("c) Multiplication\n");
    printf("d) Division\n");
    printf("e) Exit\n");
}

char correct_char(void)
{
    char target;
    //while(target != '\n') continue;
    while((target = getchar()) < 'a' || target>'e')
    {
       continue;
    }
    return target;
}

double correct_double(void)
{
    double a;
    while (scanf("%lf", &a)!=1)
        {
        continue;
        printf("Try again! The format is 2.5, or -1.78e8 or 3:\n");
        }
    return a;
}
