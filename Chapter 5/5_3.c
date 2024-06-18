#include <stdio.h>

#define HOUOUIN "EL PSY CONGROO!"
#define DAYS_IN_WEEK 7

int main()
{
    printf("Please, enter days you worked to see weeks in that number. Fine.\n");
    printf("To exit this boring procedure, enter number <=0\n");
    int days;
    scanf("%d", &days);
    while(days>0)
    {
        printf("%d days is %d weeks and %d days!\n", days, days/DAYS_IN_WEEK, days%DAYS_IN_WEEK);
        scanf("%d", &days);
    }

}
