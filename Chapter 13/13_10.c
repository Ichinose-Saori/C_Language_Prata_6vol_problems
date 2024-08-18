//use ftell(fp) to determine file size
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 60

char* s_gets(char*, int);

int main(void)
{
    FILE* fp;
    long long sizef, pos;
    char path[MAXSIZE];
    char ch;

    fprintf(stdout, "Please enter ypur file's name\n");
    s_gets(path, MAXSIZE);
    if((fp = fopen(path, "r+")) == NULL)
    {
        fprintf(stderr, "Failed  to open %s.\n",  path);
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0L, SEEK_END);
    sizef = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    fprintf(stdout, "Thise file has %lld symbols. Enter your choice, please!\n", sizef);
    while(fscanf(stdin, "%lld", &pos) == 1 && pos > -1)
    {
        fseek(fp, pos, SEEK_SET);
        while ((ch = getc(fp)) != '\n' && ch != EOF)
            putc(ch, stdout);
        putc('\n', stdout);
       
    }
    fprintf(stdout, "\nProgram has come to it's end. Goodbye!\n");
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Failed to close %s\n", path);
    }
    return 0;
}

char* s_gets(char* arr, int n)
{
    char* ret_val;
    char* find;
    ret_val = fgets(arr, n, stdin);

    if(ret_val)
    {
        find = strchr(arr, '\n');
        if (find)
            *find = '\0';
        else 
            while (getchar()!='\n')
                continue;
    }
    return ret_val;
}