#include <stdio.h>
#include <string.h>

int count_characters(void);

int main()
{
    printf("There were %d characters.\n", count_characters());
    return 0;
}

int count_characters(void)
{
    int num = 0;
    char ch;
    while((ch = getchar())!=EOF)
    {
        num++;
    }
    return num;
}
