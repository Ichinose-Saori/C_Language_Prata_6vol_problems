#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MSIZE 20
enum month {
    january, february, march, april, may, june, july, august, september, october, november, december
};
const char* words[] = {
    "January", "February", "March",
    "April", "May", "June", "July",
    "August", "September", "October",
    "November", "December"
};
const int days[] = {
    31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365
};
int gimme_cor(char*, int);
char* s_gets(char*, int);

int main(void)
{
    char choice[MSIZE];
    int index;
    printf("Please enter month's name in English language from capital letter:\n");
    index = gimme_cor(choice, MSIZE);
    printf("%d days have passed up to your month from year's start.", days[index]);
    return 0;
}

char* s_gets(char* arr, int size)
{
    char* ret_val;
    char* find;
    ret_val = fgets(arr, size, stdin);
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

int gimme_cor(char* arr, int n)
{
    int option = -1;
    int i;

    while (option == -1)
    {
        s_gets(arr, n);
        for (i = 0; i <= 11; i++)
        {
            if (strcmp(arr, words[i]) == 0)
                option = i;
        }
    }
    return option;
}
