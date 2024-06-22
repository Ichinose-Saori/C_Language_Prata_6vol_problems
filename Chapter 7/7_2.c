#include <stdio.h>
#include <string.h>


int main()
{
    int oct_count=0;
    char ch;
    while((ch = getchar()) != '#')
    {
        if(ch == ' ' || ch == '\n')
            continue;
        printf("%c is %3d ", ch, ch);
        oct_count++;
        if (oct_count == 8)
          {
              printf("\n");
              oct_count = 0;
          }
    }
    printf("\nYour program is over, bye!\n");
    return 0;
}
