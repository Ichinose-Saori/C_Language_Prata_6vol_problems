#include <stdio.h>

int main()
{
    long long downB, upB;
    int program_is_down = 0;

    if (scanf("%lld", &downB)!=1 || scanf("%lld", &upB)!=1){
                printf("You broke the program, next time don't input noninteger values!\n");
        program_is_down = 1;
        return -1;
    }

    while(downB>upB)
    {
        printf("You entered incorrect data, try again!\n");
        if (scanf("%lld", &downB)!=1 || scanf("%lld", &upB)!=1){
                printf("You broke the program, next time don't input noninteger values!\n");
        program_is_down = 1;
        return -1;
        }
    }

    for (long long i = downB; i<=upB; i++)
    {
        printf("%lld %lld %lld\n", i, i*i, i*i*i);
    }

    return 0;
}
