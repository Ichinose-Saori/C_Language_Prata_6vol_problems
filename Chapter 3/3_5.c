//this "program" calculates roughly your age in seconds
#include <stdio.h>

int main()
{
    int age;
    const double sec_in_year = 3.156e7;
    scanf("%d", &age);
    printf("Your age in seconds is (very roughly) %f seconds.\n", age*sec_in_year);
    return 0;
}