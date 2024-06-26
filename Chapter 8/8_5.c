#include <stdio.h>
#include <ctype.h>
#include <math.h>

void bin_search(void);
char get_char(void);

int main()
{
    bin_search();
    return 0;
}

void bin_search(void)
{
    printf("Please, choose your number up to 10000! I'll guess it in 14 questions.\n");
    int l = 0, r = 10001, mid;
    char choice;
    while (l<r-1)
    {
        mid = (l+r)/2;
        printf("Is your number >= than %d? y/n\n", mid);
        choice = get_char();
        switch(choice)
        {
        case 'y':
            l = mid;
            break;
        case 'n':
            r = mid;
            break;
        }
    }
    printf("Your number is %d", l);
}

char get_char(void)
{
    char ch;
    while((ch = getchar()) != 'y' && (ch != 'n'))
        continue;
    return ch;
}
