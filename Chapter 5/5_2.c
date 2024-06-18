#include <stdio.h>
#define HOUOUIN "EL PSY CONGROO!"

int main()
{
    int num;
    printf("Please enter your number for this obscure exercise.\n");
    scanf("%d", &num);
    const int num_fix = num+10;

    while (num<=num_fix)
    {
        printf("%d ", num);
        num++;
    }
    printf("That's it, another one down.");
    return 0;
}
