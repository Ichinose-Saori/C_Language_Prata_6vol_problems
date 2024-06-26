#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

void average_words(void);

int main()
{
    average_words();
    return 0;
}

void average_words(void)
{
    int words = 0, letters = 0;
    char ch;
    int in_word = 0; //if it is 0 and program enters after non-printable character a symbol, set to 1
    while ((ch = getchar()) != EOF)
    {
        if (in_word == 0 && isalpha(ch) != 0)
        {
            in_word = 1;
            words++;
            letters++;
        }
        else if (in_word == 1 && isalpha(ch) != 0)
        {
            letters++;
        }
        else if (in_word == 1 && (ch == ' ' || ch == '\n' || ch == '\t'))
        {
            in_word = 0;
        }
    }
    printf("Words - %d, letters - %d\n", words, letters);
    printf("The average amount of letter in \"words\" is %lf", (double)letters / (double)words);
}
