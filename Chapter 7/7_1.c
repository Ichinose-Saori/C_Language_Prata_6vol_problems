#include <stdio.h>
#include <string.h>


int main()
{
    char ch;
    int space, newl, other;
    space = newl = other = 0;
    while((ch = getchar()) != '#')
    {
        if (ch == ' ')
            space++;
        else if (ch == '\n')
            newl++;
        else other++;
    }
    int sum = space + newl + other;
    if (sum==0)
        printf("You haven't entered anything :(\n");
    else printf("There are %d spaces, %d new line symbols and %d others.\n", space, newl, other);
    return 0;
}
