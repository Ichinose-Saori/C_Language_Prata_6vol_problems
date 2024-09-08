#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CAPACITY 12
#define MAXLEN 40

struct seat{
    int is_seated; //1 if yes, 0 if no
    char name[MAXLEN];
    char surname[MAXLEN];
};

struct plane{
    struct seat arr[CAPACITY];
    int free_sp;
};

char * s_gets(char* arr, int n);
char corchar(void);
void show_free(struct plane *);
void initialise_plane(struct plane *);
void sort_me(const struct plane*);
int sort_me_comp(const struct seat *, const struct seat *);
void add_reservation(struct plane*);
int cor_int(int left, int right);
void cancel_booking(struct plane*);

int main(void)
{
    char menu_p;
    struct plane Chidori;
    initialise_plane(&Chidori);
    puts("Welcome to Colossus Airlines!");
    menu_p = corchar();
    while (menu_p != 'f')
    {
        switch (menu_p)
        {
            case 'a':
            {
                printf("%d seats left. Hurry up!\n", Chidori.free_sp);
            }
            break;
            case 'b':
            {
                show_free(&Chidori);
            }
            break;
            case 'c':
            {
                sort_me(&Chidori);
            }
            break;
            case 'd':
            {
                add_reservation(&Chidori);
            }
            break;
            case 'e':
            {
                cancel_booking(&Chidori);
            }
        }
        menu_p = corchar();
    }
    return 0;
}

char * s_gets(char* arr, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(arr, n, stdin);
    if (ret_val)
    {
        find = strchr(arr, '\n');
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
    puts("Please, choose an option that interests you:");
    puts("a) Show how many seats are available");
    puts("b) Show free seats");
    puts("c) Show people boarding seats in alphabetic oreder");
    puts("d) Book a seat");
    puts("e) Cancel your reservation");
    puts("f) Exit");
    scanf("%c", &a);
    while (strchr("abcdef", a) == NULL)
        scanf("%c", &a);
    while (getchar()!='\n')
        continue;
    return a;
}

void show_free(struct plane * temp)
{
    printf("I understand. Preparing information for you.\n");
    printf("Free seats are:\n");
    for (int i = 0; i<CAPACITY; i++)
    {
        if (temp->arr[i].is_seated == 0)
            printf("%d ", i+1);
    }
    putchar('\n');
}

void initialise_plane(struct plane * pt)
{
    pt->free_sp = CAPACITY;
    for (int i = 0; i<CAPACITY; i++)
    {
        pt->arr[i].is_seated = 0;
    }
}

void sort_me(const struct plane* pt)
{
    int index = 0;
    static int array[CAPACITY];
    for (int i = 0; i<CAPACITY; i++)
    {
        if (pt->arr[i].is_seated == 1)
        {
             array[index] = i;
             index++;
        } 
    }
    for (int i = 0; i<index-1; i++)
    {
        int temp;
        for (int j = i+1; j<index; j++)
        {
            if(sort_me_comp(&pt->arr[array[i]], &pt->arr[array[j]]) >= 0)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    for (int i = 0; i<index; i++)
    {
        printf("%s %s takes number %d seat\n", pt->arr[array[i]].surname, pt->arr[array[i]].name, array[i]+1);
    }
}

int sort_me_comp(const struct seat* one, const struct seat* two)
{
    if (strcmp(one->surname, two->surname) != 0)
        return strcmp(one->surname, two->surname);
    else return (strcmp(one->name, two->name));
}

void add_reservation(struct plane* pt)
{
    int choice;
    int correct = 0;
    show_free(pt);
    puts("Choose a seat");
    choice = cor_int(1, CAPACITY);
    while(correct == 0)
    {
        if(pt->arr[choice-1].is_seated == 0)
            correct = 1;
        else 
            choice = cor_int(1, CAPACITY);
    }
    puts("Enter passenger's surname");
    s_gets(pt->arr[choice-1].surname, MAXLEN);
    puts("Enter passenger's name");
    s_gets(pt->arr[choice-1].name, MAXLEN);
    pt->arr[choice-1].is_seated = 1;
    pt->free_sp--;
}

int cor_int(int left, int right)
{
    int temp;
    while (scanf("%d", &temp) != 1 || temp<left || temp>right)
    {
        printf("Please enter an integer from %d to %d\n", left, right);
        while (getchar()!='\n')
            continue;
    }
    while (getchar()!='\n')
        continue;
    return temp;
}

void cancel_booking(struct plane * pt)
{
    int choice;
    int correct = 0;
    show_free(pt);
    puts("Choose a book to cancel");
    choice = cor_int(1, CAPACITY);
    while(correct == 0)
    {
        if(pt->arr[choice-1].is_seated == 1)
            correct = 1;
        else 
            choice = cor_int(1, CAPACITY);
    }
    pt->arr[choice-1].is_seated = 0;    
}
