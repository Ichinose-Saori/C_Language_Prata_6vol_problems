#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


int main()
{
    int friends = 5, weeks = 1;
    while (friends<150)
    {
        friends = (friends-weeks)*2;
        weeks++;
        printf("%d\n", friends);
    }
    printf("%d", weeks);
    return 0;
}
