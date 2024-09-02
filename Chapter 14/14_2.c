#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXMON 40
#define MONTH 12
char array[12][MAXMON] = {"january", "february", "march", "april", "may", "june", 
    "july", "august", "september", "october", "november", "december"};
int calendar[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int corrmonth(int);
int corrday(void);
int validate_the_date(int, int, int);
void get_data(int *, int *, int *);
int calculate_date(int, int, int);

int main(void)
{
    int day = 0, year = 0;
    int month = 0;
    while(1)
    {
        get_data(&day, &month, &year);
        if (validate_the_date(day, month, year)==0)
            break;
    }
    printf("%d has passed since beginning of the year. Bye!", calculate_date(day, month, year));
    return 0;
}

int corrmonth(int size)
{
    static char month[MAXMON];
    while (1)
    {
    scanf("%s", month);
    for (int i = 0; i<size; i++)
    {
        month[i] = tolower(month[i]);
    }
    int flag = 0;
    for (int i = 0; i<strlen(month); i++)
    {
        if (isdigit(month[i]) == 0)
            flag = 1;
    }
    if (flag)
    {
        for (int i = 0; i<strlen(month); i++)
        {
            month[i] = tolower(month[i]);
        }
        for (int i = 0; i < MONTH; i++)
        {
            if (strcmp(month, array[i]) == 0)
                return i+1;
            if (strlen(month) == 3 && strncmp(month, array[i], 3) == 0)
                return i+1;
        }
        // return 0; if succesful
    }
    else 
    {
        int n;
        n = atoi(month);
        if (n>0 && n<13)
        {
            return n;
        }
    }
    puts("Damn, try again, acceptable entries are 1-12, month full names or 3 first letters. Whatever.");
    }
}

int corrday(void)
{
    int n;
    while (scanf("%d", &n) != 1 || (n<1 || n>31))
    {
        puts("Not correct, try again!");
        while(getchar()!= '\n')
            continue;
    }
    while (getchar() != '\n')
        continue;
    return n;
}

int validate_the_date(int day, int month, int year)
{
    int leap;
    int correct = 1;
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        leap = 1;
    switch(month)
    {
        case 1:
            if (day<32)
                correct = 0;
            break;
        case 2:
            if (leap)
            {
                if (day<30)
                    correct = 0;
            }
            else 
            {
                if (day<29)
                    correct = 0;
            }
            break;
        case 3:
            if (day<32)
                correct = 0;
            break;
        case 4:
            if (day<31)
                correct = 0;
            break;
        case 5:
            if (day<32)
                correct = 0;
            break;
        case 6:
            if (day < 31)
                correct = 0;
            break;
        case 7:
            if (day <32)
                correct = 0;
            break;
        case 8:
            if (day < 32)
                correct = 0;
            break;
        case 9:
            if (day < 31)
                correct = 0;
            break;
        case 10:
            if (day<32)
                correct = 0;
            break;
        case 11:
            if (day<31)
                correct = 0;
            break;
        case 12:
            if (day<32)
                correct = 0;
            break;
    }
    return correct;
}
void get_data(int * day, int * month, int * year)
{
    puts("Enter a correct day:");
    *day = corrday();
    puts("Now enter a correct month:");
    *month = corrmonth(MAXMON);
    puts("Now enter your year:");
    scanf("%d", year);
    puts("Current date is:");
    printf("%d.%d.%d\n", *day, *month, *year);
}

int calculate_date(int day, int month, int year)
{
    int leap;
    int sum = 0;
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        leap = 1;
    for (int i = 1; i<month; i++)
    {
        if (i == 2)
        {
            if (leap == 1)
                sum+=29;
            else sum+=28;
        }
        else
            sum += calendar[i-1];
    }
    sum += day;
    return sum;
}
