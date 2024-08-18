#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char* argv[])
{
    int count;
    char ch;
    if (argc < 2)
    {
        fprintf(stderr, "Master, don't be so silly. Enter at least a character in the command line.\n");
        exit(EXIT_FAILURE);
    }
    if (argc < 3)
    {
        count = 0;
        fprintf(stdout, "Programs is working in ripoff_stdin mode:\n");
        while ((ch = getchar()) != EOF)
        {
            if (ch == argv[1][0]) count++;
        }
        fprintf(stdout, "There were %d \'%c\' symbols in your input.\n", count, argv[1][0]);
    }
    else
    {
        fprintf(stdout, "Program is working in command line mode:\n");
        FILE* fstr;
        for (int i = 2; i<argc; i++)
        {
            count = 0;
            if ((fstr = fopen(argv[i], "r")) == NULL)
            {
                fprintf(stderr, "Failed to open file from argv%d," 
                " proceeding to nex file\n", i);
                continue;
            }
            while ((ch = getc(fstr)) != EOF)
            {
                if (ch == argv[1][0]) count++;
            }
            fprintf(stdout, "There were %d \'%c\' symbols in file %s\n", count, argv[1][0], argv[i]);
            if (fclose(fstr) != 0)
            {
                fprintf(stderr, "Failed to close a file. Terminating programm in:\n");
                for (int i = 3; i>0; i--)
                {
                    fprintf(stderr, "%d\n", i);
                    Sleep(1000);
                }
            }
        }
    }
    fprintf(stdout, "Terminating program in:\n");
    for (int i = 3; i>0; i--)
                {
                    fprintf(stderr, "%d\n", i);
                    Sleep(1000);
                }
    return 0;
}