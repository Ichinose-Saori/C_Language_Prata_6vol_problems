#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct text_prop {
    unsigned int id : 8;
    unsigned int sizee : 7;
    unsigned int : 1;
    unsigned int align : 2;
    unsigned int bold : 1;
    unsigned int curs : 1;
    unsigned int lined : 1;
};

void initialise_tp(struct text_prop*);
char get_corch(void);
void menu_text(void);
void show_prop(const struct text_prop*);

int main(void)
{
    char menu;
    unsigned int tempp;
    struct text_prop times_nr;
    initialise_tp(&times_nr);
    show_prop(&times_nr);
    menu_text();
    printf("\n");
    char Lu = get_corch();
    while (Lu != 'g')
    {
        switch (Lu)
        {
        case 'a':
        {
            puts("Enter you id, but I won't check it, so be sure~~:");
            scanf("%u", &tempp);
            times_nr.id = tempp;
        }
        break;
        case 'b':
        {
            puts("Enter you size, but I won't check it, so be sure~~:");
            scanf("%u", &tempp);
            times_nr.sizee = tempp;
        }
        break;
        case 'c':
        {
            puts("Enter you alignment, but I won't check it, so be sure~~:");
            scanf("%u", &tempp);
            times_nr.align = tempp;
        }
        break;
        case 'd':
        {
            puts("Enter you Bold preference, but I won't check it, so be sure~~:");
            scanf("%u", &tempp);
            times_nr.bold = tempp;
        }
        break;
        case 'e':
        {
            puts("Enter you Cursive preference, but I won't check it, so be sure~~:");
            scanf("%u", &tempp);
            times_nr.curs = tempp;
        }
        break;
        case 'f':
        {
            puts("Enter you lined preference, but I won't check it, so be sure~~:");
            scanf("%u", &tempp);
            times_nr.lined = tempp;
        }
        break;
        }
        show_prop(&times_nr);
        menu_text();
        Lu = get_corch();
    }
    return 0;
}

void initialise_tp(struct text_prop* temp)
{
    temp->id = 1;
    temp->sizee = 12;
    temp->align = 0;
    temp->bold = 0;
    temp->curs = 0;
    temp->lined = 0;
}

char get_corch(void)
{
    char temp;
    temp = getchar();
    while (strchr("abcdefg", temp) == NULL)
    {
        printf("Choose out of said options.\n");
        temp = getchar();
    }
    while (getchar() != '\n')
        continue;
    return temp;
}

void menu_text(void)
{
    puts("a) Change font");
    puts("b) Change size");
    puts("c) Change alignment");
    puts("d) Toggle Bold");
    puts("e) Toggle cursive");
    puts("f) Toggle lined");
    puts("g) Exit");
}

void show_prop(const struct text_prop* sample)
{
    printf("  ID     SIZE     ALIGNMENT     B    C    L\n");
    printf("  %d        %d      ", sample->id, sample->sizee);
    if (sample->align == 0)
        printf("left       ");
    else if (sample->align == 1)
        printf("center     ");
    else
        printf("right      ");
    if (sample->bold == 0)
        printf("off  ");
    else
        printf("on   ");
    if (sample->curs == 0)
        printf("off  ");
    else
        printf("on   ");
    if (sample->lined == 0)
        printf("off\n");
    else
        printf("on\n");
}
