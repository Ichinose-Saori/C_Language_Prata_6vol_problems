#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 80

char* s_gets(char*, int);
void copy_ed(FILE*, FILE*);

int main(void)
{
    char arrout[SIZE];
    char arrin[SIZE];
    fprintf(stdout, "Please, enter name of file that is to be copied.\n");
    s_gets(arrin, SIZE);
    fprintf(stdout, "Please, enter name of file that is to be written\n");
    s_gets(arrout, SIZE);
    FILE* fout;
    FILE* fin;
    if ((fout = fopen(arrout, "w")) == NULL)
    {
        fprintf(stdout, "Failed to open %s\n", arrout);
        exit(EXIT_FAILURE);
    }
    if ((fin = fopen(arrin, "r")) == NULL)
    {
        fprintf(stdout, "Failed to open %s\n", arrin);
        exit(EXIT_FAILURE);
    }
    copy_ed(fin, fout);
    fclose(fin);
    fclose(fout);
    return 0;
}

char* s_gets(char* arr, int size)
{
    char* ret_val;
    char* find;

    ret_val = fgets(arr, size, stdin);
    if (ret_val)
    {
        find = strchr(arr, '\n');
        if (find != NULL)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

void copy_ed(FILE* source, FILE* dest)
{
    char ch;
    while ((ch = getc(source)) != EOF)
    {
        putc(toupper(ch), dest);
    }
}