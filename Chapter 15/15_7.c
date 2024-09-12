//YES I'M AWARE THAT USING BIT_WISE OPERATIONS
//WAS INTENDED TO SAVE MEMORY BUT I'M NOT 
//SPENDING MY TIME ON THIS BIAS
//SO I REALLY USED BITWISE BUT IN A BAD WAY, HEHEHEHEHEHE

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char get_corch(void);
void menu_text(void);
void show_prop(const unsigned int);

int main(void)
{
    char fish;

    int temp;
    unsigned int ppt = 1048575;
    menu_text();
    show_prop(ppt);
    size_t ssss;
    fish = get_corch();
    while (fish != 'g')
    {
        switch (fish)
        {
        case 'a':
        {
            puts("Enter you id, but I won't check it, so be sure~~:");
            scanf("%u", &temp);
            ppt &= ~255;
            ppt |= temp;
        }
        break;
        case 'b':
        {
            puts("Enter you size, but I won't check it, so be sure~~:");
            scanf("%u", &temp);
            ppt &= ~32512;
            temp <<= 8;
            ppt |= temp;
        }
        break;
        case 'c':
        {
            puts("Enter you alignment, but I won't check it, so be sure~~:");
            scanf("%u", &temp);
            ppt &= ~98304;
            temp <<= 15;
            ppt |= temp;
        }
        break;
        case 'd':
        {
            puts("Enter you Bold preference, but I won't check it, so be sure~~:");
            scanf("%u", &temp);
            ppt &= ~131072;
            temp <<= 17;
            ppt |= temp;
        }
        break;
        case 'e':
        {
            puts("Enter you Cursive preference, but I won't check it, so be sure~~:");
            scanf("%u", &temp);
            ppt &= ~262144;
            temp <<= 18;
            ppt |= temp;
        }
        break;
        case 'f':
        {
            puts("Enter you lined preference, but I won't check it, so be sure~~:");
            scanf("%u", &temp);
            ppt &= ~524288;
            temp <<= 19;
            ppt |= temp;
        }
        break;
        }
        show_prop(ppt);
        menu_text();
        fish = get_corch();
    }
    return 0;
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

void show_prop(const unsigned int num)
{
    int lens[6] = { 8, 7, 2, 1, 1, 1 };
    int vals[6] = { 0 };
    int collect = 0;
    unsigned int copy = num;
    int two_deg;
    for (int i = 0; i < 6; i++)
    {
        two_deg = 1;
        for (int j = 0; j < lens[i]; j++)
        {
            if ((copy & 1) == 1)
                vals[i] += two_deg;
            copy >>= 1;
            two_deg *= 2;
        }
    }
    printf("  ID     SIZE     ALIGNMENT     B    C    L\n");
    printf("  %d        %d      ", vals[0], vals[1]);
    if (vals[2] == 0)
        printf("left       ");
    else if (vals[2] == 1)
        printf("center     ");
    else
        printf("right      ");
    if (vals[3] == 0)
        printf("off  ");
    else
        printf("on   ");
    if (vals[4] == 0)
        printf("off  ");
    else
        printf("on   ");
    if (vals[5] == 0)
        printf("off\n");
    else
        printf("on\n");
}
