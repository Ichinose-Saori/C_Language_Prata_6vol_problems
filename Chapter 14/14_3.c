#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

char* s_gets(char *st, int n);
struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

void sort_bubble(struct book * arr[], int count, int mode);

int main(void)
{
    struct book library[MAXBKS];
    struct book* plibrary[MAXBKS];
    int count = 0;
    int index, filecount;
    FILE * pbooks;
    int size = sizeof(struct book);
    if ((pbooks = fopen("book.dat", "a+b")) == NULL)
    {
        fputs("Failed to open book.dat\n", stderr);
        exit(EXIT_FAILURE);
    }

    rewind(pbooks);
    while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
    {
        if (count == 0)
            puts("Current file content:");
        printf("%s written by %s: $%.2f\n", library[count].title,
            library[count].author, library[count].value);
        plibrary[count] = &library[count];
        count++;
    }
    filecount = count;
    if (count == MAXBKS)
    {
        fputs("File book.dat is full", stderr);
        exit(2);
    }
    puts("Enter names of your new books.");
    puts("Press ENTER in the beginning of a line to end work of this program.");
    while(count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        puts("Now enter a name of the author.");
        s_gets(library[count].author, MAXAUTL);
        puts("Now enter a price of the book.");
        scanf("%f", &library[count++].value);
        plibrary[count-1] = &library[count-1];
        while (getchar()!='\n')
            continue;
        if (count < MAXBKS)
            puts("Enter a name of your next book");
    }
    if (count > 0)
    {
        puts("Catalogue of your books by addition time:");
        for (index = 0; index<count; index++)
            printf("%s written by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
    
        puts("\nSorted in alphabetical manner");
        sort_bubble(plibrary, count, 1);
        for (int i = 0; i<count; i++)
        {
            printf("%s written by %s: $%.2f\n", plibrary[i]->title, plibrary[i]->author, plibrary[i]->value);
        }

        puts("\nSorted by the price.");
        sort_bubble(plibrary, count, 2);

        for (int i = 0; i<count; i++)
        {
            printf("%s written by %s: $%.2f\n", plibrary[i]->title, plibrary[i]->author, plibrary[i]->value);
        }
        fwrite(&library[filecount], size, count-filecount, pbooks);
    }
    else
        puts("No books? That's saddening. Let's read together!");
    puts("Program is over.");
    if (fclose(pbooks) != 0)
    {
        fprintf(stderr, "Failed to close file stream.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

char * s_gets(char* arr, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(arr, n, stdin);
    if (ret_val)
    {
        find = strchr (arr, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

void sort_bubble(struct book * arr[], int count, int mode)
{
    struct book * pp;
    if (mode == 1)
    {
        for (int i = 0; i<count; i++)
        {
            for (int j = i+1; j<count; j++)
            {
                if (strcmp(arr[i]->title, arr[j]->title) >=0)
                {
                    pp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = pp;
                }
            }
        }
    }
    else if (mode == 2)
    {
        for (int i = 0; i<count; i++)
        {
            for (int j = i+1; j<count; j++)
            {
                if (arr[i]->value > arr[j]->value)
                {
                    pp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = pp;
                }
            }
        }
    }
    else printf("Wrong entry.\n");
}
