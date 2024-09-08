#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

char* s_gets(char *st, int n);
char corchar(void);
int cor_int(int left, int right);

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
    int to_be_del;
};
void who_is_alive(struct book arr[], int count);


int main(void)
{
    struct book library[MAXBKS];
    int alive[MAXBKS];
    int count = 0;
    int index, filecount;
    FILE * pbooks;
    char menuSym;
    int size = sizeof(struct book);
    int position; //position in editing and deleting

    int to_be_int = 0;
    int to_be[MAXBKS] = {0};

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
        if (library[count].to_be_del == 1)
        {
            to_be[to_be_int] = count;
            to_be_int++;
        }
        else 
            printf("%d) %s written by %s: $%.2f\n", count+1, library[count].title,
            library[count].author, library[count].value);
        count++;
    }
    printf("Currently deleted in array %d elements\n", to_be_int);
    filecount = count;
    if (count == MAXBKS)
    {
        fputs("File book.dat is full", stderr);
        exit(2);
    }
    while((menuSym = corchar()) != 'd')
    {
        if (menuSym == 'a')
        {
            puts("Enter names of your new books.");
            puts("Press ENTER in the beginning of a line to end work of this program.");
            if (to_be_int == 0)
            {
                if (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL)
                {
                    library[count].to_be_del = 0;
                    puts("Now enter a name of the author.");
                    s_gets(library[count].author, MAXAUTL);
                    library[count].to_be_del = 0;
                    puts("Now enter a price of the book.");
                    scanf("%f", &library[count++].value);
                
                    while (getchar()!='\n')
                    continue;
                    if (count < MAXBKS)
                    puts("Enter a name of your next book");
                }
            }
            else 
            {
                if (count-to_be_int < MAXBKS && s_gets(library[to_be[to_be_int-1]].title, MAXTITL) != NULL)
                {
                    library[to_be[to_be_int-1]].to_be_del = 0;
                    puts("Now enter a name of the author.");
                    s_gets(library[to_be[to_be_int-1]].author, MAXAUTL);
                    library[to_be[to_be_int-1]].to_be_del = 0;
                    puts("Now enter a price of the book.");
                    scanf("%f", &library[to_be[to_be_int-1]].value);
        
                    while (getchar()!='\n')
                    continue;

                    to_be_int--;

                    if (count-to_be_int < MAXBKS)
                    puts("Enter a name of your next book");
                }
            }
        }
        else if (menuSym == 'b')
        {
            if (count == 0)
                {
                printf("Can't edit if there's nothing to see, sorry\n");
            }
            else {
            puts("Positions available for editing:");
            who_is_alive(library, count);
            position = cor_int(1, count);
            printf("%d is your pos\n", position);
            printf("%d) %s written by %s: $%.2f\n", position, library[position-1].title, library[position-1].author, library[position-1].value);
            puts("Enter a new name for your book");
            s_gets(library[position-1].title, MAXAUTL);
            puts("Now enter a name of the author.");
            s_gets(library[position-1].author, MAXAUTL);
            puts("Now enter a price of the book.");
            scanf("%f", &library[position-1].value);
            while (getchar()!='\n')
                continue;
            }
        }
        else if (menuSym == 'c')
        {
            puts("Positions available for deleting:");
            who_is_alive(library, count);
            position = cor_int(1, count);
            library[position-1].to_be_del = 1;
            to_be[to_be_int] = position-1;
            to_be_int++;
        }
    }
    
    if (count > 0)
    {
        puts("Catalogue of your books:");
        for (index = 0; index<count; index++)
        {
            if (library[index].to_be_del == 0)
            {
                printf("%d) %s written by %s: $%.2f\n", index+1, library[index].title, library[index].author, library[index].value);
            }
        }
        fclose(pbooks);
        if ((pbooks = fopen("book.dat", "w")) == NULL)
        {
            fputs("Failed to open book.dat\n", stderr);
            exit(EXIT_FAILURE);
        }
        fclose(pbooks);
        if ((pbooks = fopen("book.dat", "a+b")) == NULL)
        {
        fputs("Failed to open book.dat\n", stderr);
        exit(EXIT_FAILURE);
        }
        fwrite(&library[0], size, count, pbooks);
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

char corchar(void)
{
    char a;
    puts("Welcome to your books list.");
    puts("What do you need today? Enter a letter to follow:");
    puts("a) Add more");
    puts("b) Edit chosen position");
    puts("c) Delete chosen position");
    puts("d) Exit the program");
    scanf("%c", &a);
    while (strchr("abcd", a) == NULL)
        scanf("%c", &a);
    while (getchar()!='\n')
        continue;
    return a;
}

void who_is_alive(struct book arr[], int count)
{
    for (int i = 0; i<count; i++)
    {
        if (arr[i].to_be_del == 0)
            printf("%d ", i+1);
    }
    putchar('\n');
}

int cor_int(int left, int right)
{
    int a;
    while (scanf("%d", &a) != 1 || a<left || a>right)
    {
        printf("Please enter a number from %d to %d\n", left, right);
    }
    while (getchar() != '\n')
        continue;
    return a;
}
