#include <stdio.h>
#include <ctype.h>

void counteer(void);

int main()
{
    counteer();
    return 0;
}

void counteer()
{
    char ch;
    while((ch = getchar()) != EOF)
    {
        if (isalpha(ch))
        {
            ch = tolower(ch);
            printf("%c is %d\n", ch, ch-'a'+1);
        }
        else printf("-1\n");
    }
}

