#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char ch;
    FILE* fstr;

    if (argc < 2)
    {
        printf("Using this program:\n");
        printf("%s file_1 file_2 ... file_n. Don't be so silly next time $__$\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++)
    {
        if ((fstr = fopen(argv[i], "r")) == NULL)
        {
            fprintf(stdout, "Failed to open file %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }
        fprintf(stdout, "Ready to show file (%d):\n", i);
        while ((ch = getc(fstr)) != EOF)
            putc(ch, stdout);
        fclose(fstr);
        fprintf(stdout, "\n");
    }
    fprintf(stdout, "\n\nI've given all you requested, master U-U\n");
    return 0;
}