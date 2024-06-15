#include <stdio.h>

int main(void)
{
    double cups;
    printf("Hello, this is program to see transfer from cups to other AMERICAN values.\nPlease, proceed to enter your volume in cups!\n");
    scanf("%lf", &cups);
    printf("%f cups are equal to:\n\t%f pints;\n\t%f ounces;\n\t%f tbspoons;\n\t%f teaspoons.\n", cups, cups/2, 8*cups, 16*cups, 48*cups);
    return 0;
}