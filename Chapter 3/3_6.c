#include <stdio.h>

int main(void)
{
    int quarters = 0, grams = 0;
    const double water_m = 3.0e-23;
    scanf("%d", &quarters);
    grams = quarters*950;
    printf("In %d quarts of water there are %e molecules.\n", quarters, grams/water_m);
    return 0;
}