#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

void check_checkerson(FILE*);
void wipe_me_baby(char *, int);

int main(void)
{
    FILE* fp;
    FILE* fbin;
    long long count=0;
    char words[MAX];
    char number[MAX+18];
    //check_checkerson(fbin);
    //
      if ((fbin = fopen("tpp", "r+b")) == NULL)
    {
        if ((fbin = fopen("tpp", "wb")) == NULL)
        {
            fprintf(stderr, "File opening error1, duh.\n");
            exit(EXIT_FAILURE);
        }
        long long a = 1;
        fwrite(&a, sizeof(long long), 1, fbin);
        if (fclose(fbin) != 0)
        {
            fprintf(stderr, "Closing file error.\n");
            exit(EXIT_FAILURE);
        }
        if ((fbin = fopen("tpp", "r+b")) == NULL)
        {
            fprintf(stderr, "File opening error2, duh.\n");
            exit(EXIT_FAILURE);
        }
        rewind(fbin);
        long long b;
        fread(&b, sizeof(long long), 1, fbin);
        fprintf(stdout, "There was no file so I decided to create it and fill with %lld :)\n", b);  
    }
    //
    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stdout, "Failed to open \"wordy\".\n");
        exit(EXIT_FAILURE);
    }
    puts("Enter words to add into the file;");
    puts("To terminate the program, enter \'#\' as input value.");
    while((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
    {
        rewind(fbin);
        fread(&count, sizeof(long long), 1, fbin);
        wipe_me_baby(number, MAX+18);
        sprintf(number, "%lld", count);
        fprintf(fp, "%s", number);
        fprintf(fp, ")%s\n", words);
        count++;
        rewind(fbin);
        fwrite(&count, sizeof(long long), 1, fbin);
    }
    puts("File's content:");
    rewind(fp);
    while(fscanf(fp, "%s", words) == 1)
        puts(words);
    puts("Ready!");
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Failed to close a file.\n");
    }
    return 0;
}

void check_checkerson(FILE* fbin)
{
     if ((fbin = fopen("tpp", "r+b")) == NULL)
    {
        if ((fbin = fopen("tpp", "wb")) == NULL)
        {
            fprintf(stderr, "File opening error1, duh.\n");
            exit(EXIT_FAILURE);
        }
        long long a = 1;
        fwrite(&a, sizeof(long long), 1, fbin);
        if (fclose(fbin) != 0)
        {
            fprintf(stderr, "Closing file error.\n");
            exit(EXIT_FAILURE);
        }
        if ((fbin = fopen("tpp", "r+b")) == NULL)
        {
            fprintf(stderr, "File opening error2, duh.\n");
            exit(EXIT_FAILURE);
        }
        rewind(fbin);
        long long b;
        fread(&b, sizeof(long long), 1, fbin);
        fprintf(stdout, "There was no file so I decided to create it and fill with %lld :)\n", b);  
    }
}

void wipe_me_baby(char * arr, int size)
{
    for (int i = 0; i<size; i++)
    {
        arr[i] = '\0';
    }
}