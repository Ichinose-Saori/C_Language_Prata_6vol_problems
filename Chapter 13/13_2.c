#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 4096

void copy(FILE*, FILE*);

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Use arguments of the command line as follows:\n");
        fprintf(stderr, "%s source_file copy_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (strcmp(argv[1], argv[2]) == 0)
    {
        fprintf(stderr, "Can't copy file in itself, sorry I-I.\n");
        exit(EXIT_FAILURE);
    }
    FILE* sf;
    FILE* cf;
    if ((sf = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "Failed to open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((cf = fopen(argv[2], "wb")) == NULL)
    {
        fprintf(stderr, "Failed to open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    copy(sf, cf);
    printf("Copied succesfully.\n");
    fclose(sf);
    fclose(cf);
    return 0;
}

void copy(FILE* source, FILE* copy)
{
    size_t bytes;
    static char temp[BUFSIZE];
    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source))>0)
        fwrite(temp, sizeof(char), bytes, copy);
}