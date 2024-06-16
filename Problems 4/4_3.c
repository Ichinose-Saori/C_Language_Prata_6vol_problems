#include <stdio.h>
#include <string.h>

int main()
{
    double number;
    scanf("%lf", &number);
    printf("%.1lf %.1le\n", number, number);
    printf("%+.3lf %+.3le\n", number, number);
    return 0;
}
