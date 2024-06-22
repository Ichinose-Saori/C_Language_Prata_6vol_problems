#include <stdio.h>
#include <string.h>


int main()
{
    int amoIN = 0, amoODD = 0;
    int sumIN = 0, sumODD = 0;
    int temp;
    int ok = 1;
    while((ok = ((scanf("%d", &temp)) == 1)) && (temp!=0))
    {
        amoIN++;
        sumIN+=temp;
        if (temp % 2 == 1)
        {
            amoODD++;
            sumODD+=temp;
        }
    }

    if(!ok)
    {
        printf("Man, come on, you've broken your program!\nEnter only integer values.\n");
        return -1;
    }
    if (amoIN == 0)
    {
        printf("You haven't entered anything!\n");
        return 0;
    }
    else if (amoODD == 0)
        printf("There are %d integers, and their average is %lf\n", amoIN, (double)sumIN/amoIN);
    else {
        printf("There are %d integers, and their average is %lf\n", amoIN, (double)sumIN/amoIN);
        printf("There are %d odd integers and their average is %lf", amoODD, (double)sumODD/amoODD);
    }


    return 0;
}
