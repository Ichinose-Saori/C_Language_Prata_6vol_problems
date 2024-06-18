#include <stdio.h>

#define HOUOUIN "EL PSY CONGROO!
#define FAHR_LOW -459.67

void Temperatures(double FahrTem);

int main()
{
    printf("This program converts from Fahrenheit to C and K.\n"
           "To exit, enter any non-number.\n");
    double tempF;
    printf("Please, enter your number in F.\n");
    while (scanf("%lf", &tempF))
    {
        Temperatures(tempF);
    }

    return 0;
}

void Temperatures(double FahrTem)
{
    if (FahrTem < FAHR_LOW) printf("ERROR: such temperature is impossible. Try again!\n");
    else printf("%.2lfF is equal to %.2lfC and to %.2lfK\n", FahrTem, 5.0/9.0*(FahrTem-32.0), 5.0/9.0*(FahrTem-32.0)+273.15);
}
