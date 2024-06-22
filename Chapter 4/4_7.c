#include <stdio.h>
#include <float.h>

int main()
{
    printf("For double amount of digits is %d and for float it is %d\n", FLT_DIG, DBL_DIG);
    float fl = 1.0/3.0;
    double db = 1.0/3.0;
    printf("%.4f %.4lf\n", fl, db);
    printf("%.12f %.12lf\n", fl, db);
    printf("%.16f %.16lf\n", fl, db);
    return 0;
}
