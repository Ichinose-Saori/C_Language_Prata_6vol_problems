#include <stdio.h>

int main(void)
{
    const float in_cm_coef = 2.54;
    float height_cm = 0;
    printf("Please, enter you height in cantimeters!\n");
    scanf("%f", &height_cm);
    printf("Your height in inches is %f\n", height_cm/in_cm_coef);
    return 0;
}