#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


int main()
{
    printf("Dafna holds 100$ with simple 10%% and Deidra has 100$ with exponential 5%%. Let's see, when Deidra will have more money.\n");
    int years = 1;
    double Dafna = 100.0, Deidra = 100.0;
    Dafna+=10.0;
    Deidra*=1.05;
    while (Dafna>Deidra)
    {
        years++;
        Dafna+=10.0;
        Deidra*=1.05;
        printf("%lf %lf\n", Dafna, Deidra);
    }
    printf("In %d years.\n", years);
    return 0;
}
