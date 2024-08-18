#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 30

char* s_gets(char*, int);

int main(void)
{
    FILE *in, *out;
    int ch;
    char name[LEN];
    char copyn[LEN];
    int count = 0;
    s_gets(name, LEN);
    if ((in = fopen(name, "r")) == NULL)
    {
        fprintf(stderr, "Failed to open %s\n", name);
        exit(EXIT_FAILURE);
    }
    strncpy(copyn, name, LEN);
    strncpy(name, copyn, LEN-5);
    name[LEN-5] = '\0';
    strcat(name, ".red");
    if ((out = fopen(name, "w")) == NULL)
    {
        fprintf(stderr, "Failed to create output file.");
        exit(3);
    }
    while ((ch = getc(in)) != EOF)
        if (count++ %3 == 0)
        putc(ch, out);
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error: failed to close opened files.\n");
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
        if (find != NULL)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}