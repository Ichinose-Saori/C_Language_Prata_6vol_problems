#include <stdio.h>
#include <string.h>


int main()
{
    char ch;
    int changes = 0;
    while((ch = getchar()) != '#')
    {
        if (ch == '.')
        {
            putchar('!');
            changes++;
        }
        else if (ch == '!')
        {
            printf("!!");
            changes++;
        }
        else putchar(ch);
    }
    printf("\n");
    printf("I've changed %d symbols.\n", changes);
    return 0;
}
