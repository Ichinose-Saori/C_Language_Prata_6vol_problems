#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 80

char* s_gets(char*, int);
void work (char*, char*);

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        fprintf(stdout, "Working interactively Q_Q\n");
        char arrone[SIZE];
        char arrtwo[SIZE];
        s_gets(arrone, SIZE);
        s_gets(arrtwo, SIZE);
        work(arrone, arrtwo);
    }
    else 
    {
        fprintf(stdout, "Working with a command line U_I\n");
        work(argv[1], argv[2]);
    }
    return 0;
}

char* s_gets(char* arr, int n)
{
    char* ret_val;
    char* find;
    ret_val = fgets(arr, n, stdin);
    if (ret_val)
    {
        find = strchr(arr, '\n');
        if (find)
            *find = '\0';
        else 
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

void work(char* none, char* ntwo)
{
    char ch;
        FILE *fone, *ftwo;
        int one = 1, two = 1;
        if ((fone = fopen(none, "r")) == NULL || (ftwo = fopen(ntwo, "r")) == NULL)
        {
            fprintf(stderr, "Failed to open files. :(\n");
            exit(EXIT_FAILURE);
        }
        while (one+two)
        {
            if(one)
            {
                while((ch = getc(fone)) != EOF)
                {
                    putchar(ch);
                    if (ch == '\n') break;
                }
                if (ch == EOF) 
                {
                    one = 0;
                    putchar('\n');
                }
            }
            if (two)
            {
                while((ch = getc(ftwo)) != EOF)
                {
                    putchar(ch);
                    if (ch == '\n') break;
                }
                if (ch == EOF)
                {
                    two = 0;
                    putchar('\n');
                } 
            }
        }
        if (fclose(fone) != 0 || fclose(ftwo) != 0)
        {
            fprintf(stderr, "Failed to close opened files\n");
            exit(EXIT_FAILURE);
        }
}