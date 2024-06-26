#include <stdio.h>

char get_first(void);

int main()
{
    printf("First visible symbol is %c\n", get_first());
    printf("First visible symbol is %c\n", get_first());
    return 0;
}

char get_first(void)
{
    char target;
    char ch;
    while((target = getchar()) == ' ' || target == '\n' || target == '\t') continue;
    while ((ch=getchar())!= '\n') continue;
    return target;
}
