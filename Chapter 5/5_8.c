#include <stdio.h>

#define HOUOUIN "EL PSY CONGROO!

int main()
{
    printf("Please, enter your divisor operator (it's permanent).\n");
    int oper;
    scanf("%d", &oper);
    printf("Enter your guinea pigs in int format.\n"
            "To exit our program, type any number less than 0\n");
    int guinea;
    scanf("%d", &guinea);
    while (guinea>0)
    {
        printf("%d%%%d=%d\n", guinea, oper, guinea%oper);
        printf("Enter your guinea pigs in int format.\n"
            "To exit our program, type any number less than 0\n");
        scanf("%d", &guinea);
    }
    return 0;
}
