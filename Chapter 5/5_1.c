#include <stdio.h>

#define HOUOUIN "EL PSY CONGROO!"
#define MIN_IN_SEC 60


int main()
{
    int minutes;
    printf("Please, enter time you want to reshape in minutes.\n");
    printf("If you want this program to perish, enter value <= 0.\n");
    scanf("%d", &minutes);
    while (minutes>0)
    {
        printf("%d minutes is %d hours and %d minutes!\n", minutes, minutes/MIN_IN_SEC, minutes%MIN_IN_SEC);
        scanf("%d", &minutes);
    }

    return 0;
}
