#include <stdio.h>
#include <string.h>


int main()
{
    char ch;
    int changes = 0;
    while((ch = getchar()) != '#')
    {
        switch(ch)
        {
        case '.':
            putchar('!');
            changes++;
            break;
        case '!':
            printf("!!");
            changes++;
            break;
        default:
            putchar(ch);
            break;
        }
    }
    printf("\n");
    printf("I've changed %d symbols.\n", changes);
    return 0;
}
