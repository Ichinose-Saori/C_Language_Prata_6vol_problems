#include <stdio.h>
#include <string.h>

#define ALONE 17850.0
#define HEAD 23900.0
#define MARRIED_TOG 29750.0
#define MARRIED_SEP 14875.0

void intro(void);
int input(void);

int main()
{
    int choice;
    intro();
    choice = input(); //It is guaranteed that the value lies between 1 and 5, so no checks is needed.
    while(choice != 5)
    {
        double threshold;
        switch(choice)
        {
        case 1:
            threshold = ALONE;
            break;
        case 2:
            threshold = HEAD;
            break;
        case 3:
            threshold = MARRIED_TOG;
            break;
        case 4:
            threshold = MARRIED_SEP;
            break;
        }
        double income;
        printf("Enter your income:\n");
        scanf("%lf", &income);
        if (income<=threshold) printf("Your tax will be %lf$.\n\n", income*0.15);
        else{
            printf("Your tax will be %lf$.\n\n", threshold*0.15 + (income-threshold)*0.28);
        }
        intro();
        choice = input();
    }
    return 0;
}

void intro(void)
{
    printf("Hello, today is 1988 and we are to know, how much taxes you shall pay.\n");
    printf("Please, choose the category you are in:\n");
    printf("1) Alone\n");
    printf("2) The head of the family\n");
    printf("3) Married, live together\n");
    printf("4) Married, live separated\n");
    printf("5) Exit\n");
}

int input(void)
{
    int choice;
    while((scanf("%d", &choice)!=1) || choice < 1 || choice > 5)
    {
        printf("It seems, you entered NONINTEGER VALUE or not a number from a list. Try again!\n");
        getchar();
    }
    return choice;
}
