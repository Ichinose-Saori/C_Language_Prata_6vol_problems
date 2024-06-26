#include <stdio.h>
#include <ctype.h>

void count_sym(void);

int main()
{
    count_sym();
    return 0;
}

void count_sym(void)
{
    char ch;
    int upper = 0, lower = 0, others = 0;
    while ((ch = getchar()) != EOF)
    {
        if (isupper(ch)) upper++;
        else if (islower(ch)) lower++;
        else others++;
    }
    printf("There were %d uppercase letters, %d lowercase letters and %d other symbols.\n", upper, lower, others);
}
