#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAXLEN 300

int main(int argc, char *argv[])
{
    FILE* fstr;
    char arr[MAXLEN];
    char* chp;
    char ch;
    if (argc<3)
    {
        fprintf(stderr, "To use this program, enter two command line arguments.\n"
            "Terminating the program.\n");
        exit(EXIT_FAILURE);
    }

    if ((fstr = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Failed to open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while (feof(fstr) != 1)
    {
        fgets(arr, MAXLEN, fstr);
        chp = strstr(arr, argv[1]);
        if(chp != NULL)
        {
            while (*chp != '\0')
            {
            putchar(*chp);
            chp++;
            }
        }
        ch = getc(fstr);
        if (ch == EOF) break;
        ungetc(ch, fstr);
    }
    if (fclose(fstr) != 0)
    {   
        fprintf(stderr, "Failed to close an opened file.\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}