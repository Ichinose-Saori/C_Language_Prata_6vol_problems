#include <stdio.h>
#include <float.h>

int main()
{
    float distance_mil, fuel_gal;
    printf("Please, enter distance you traveled and amount of fuel you\'ve burnt.\n");
    scanf("%f %f", &distance_mil, &fuel_gal);
    printf("Your engine gives %f per one gallon\n", distance_mil/fuel_gal);
    printf("In Europe that would be %f liters for 100 kilometers\n", 3.785*fuel_gal/1.609/distance_mil*100);
    return 0;
}
