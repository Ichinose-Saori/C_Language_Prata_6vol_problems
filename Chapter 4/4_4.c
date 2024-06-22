#include <stdio.h>
#include <string.h>

int main()
{
    char name[40];
    double height;
    printf("Please, enter your name and height in cm!\n");
    scanf("%s %lf", name, &height);
    printf("%s, your height is %.3lf\n", name, height);
    return 0;
}
