#include <stdio.h>

char get_char(void);
void chline(char, int, int);

int main()
{
    char ch;
    int rows, columns;
    ch = get_char();
    printf("Please, enter first number.\n");
    while(scanf("%d", &rows) != 1 || rows < 0)
    {
        getchar();
        continue;
    }
    printf("Please, second number.\n");
    while(scanf("%d", &columns) != 1 || columns < 0)
    {
        getchar();
        continue;
    }
    chline(ch, rows, columns);
    return 0;
}

char get_char(void)
{
    char ch;
    char cht;
    printf("Please, enter a character!\n");
    while ((ch = getchar())==' ' || ch == '\n' || ch == '\t')
    {
        continue;
    }
    cht = ch;
    while ((ch = getchar())!='\n')
        continue;
    return cht;
}

void chline(char ch, int rows, int columns)
{
    for (int i = 0; i<rows; i++)
    {
        for (int j = 0; j<columns; j++)
        {
            putchar(ch);
        }
        putchar('\n');
    }
}
