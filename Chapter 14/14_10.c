#include <stdio.h>
#include <string.h>

void fun1(void){
    printf("You called function 1\n");
}

void fun2(void){
    printf("You called function 2\n");
}

void fun3(void){
    printf("You called function 3\n");
}

char corr_char(void);

int main()
{
    void (* fp[])(void) = {fun1, fun2, fun3};
    puts("Pick from a to c, or d to stop");
    char option = corr_char();
    while (option != 'd')
    {
        switch(option)
        {
            case 'a':
            fp[0]();
            break;
            case 'b':
            fp[1]();
            break;
            case 'c':
            fp[2]();
            break;
        }
        puts("Pick from a to c, or d to stop");
        option = corr_char();
    }
    return 0;
}

char corr_char(void)
{
    char temp;
    while((temp = getchar()) != EOF && strchr("abcd", temp) == NULL)
        continue;
    return temp;
}
