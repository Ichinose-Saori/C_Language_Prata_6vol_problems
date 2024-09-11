#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void negate_me(char *);
void andd(char*, char*);
void orr(char *, char*);
void xorr(char *, char *);

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("I need two command line arguments!\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 1; i<3; i++)
    {
        negate_me(argv[i]);
    }
    andd(argv[1], argv[2]);
    orr(argv[1], argv[2]);
    xorr(argv[1], argv[2]);
    return 0;
}

void negate_me(char* arr)
{
    printf("I'm negating %s -> ", arr);
    for (int i = 0; i<strlen(arr); i++)
    {
        if (arr[i] == '0')
            printf("1");
        else printf("0");
    }
    printf("\n");
}

void andd(char* left, char* right) //so sorry for noodles code, but I want to get this done, alrigh??????
{
    int flag;
    int lennl, lennr;
    int i, j;
    printf("%s & %s is ", left, right);
    if (strlen(left) < strlen(right))
    {
        lennl = strlen(left);
        lennr = strlen(right);
        for (i = lennr-1, j = lennl-1; i > lennr - lennl-1; i--)
        {
            if (right[i] == left[j]) printf("%c", left[i]);
            else printf("0");
            j--;
         }
    }
    else
    {
        lennl = strlen(right);
        lennr = strlen(left);
        flag = 1;
        for (i = lennr-1, j = lennl-1; i > lennr - lennl-1; i--)
        {
            if (right[j] == left[i]) printf("%c", left[i]);
            else printf("0");
            j--;
        }
    }
    
    printf("\n");
}

void orr(char * left, char * right)
{
    int i, j;
    int temp;
    int big = strlen(left);
    int low = strlen(right);;
    printf("%s | %s = ", left, right);
    if (big<low)
    {
        temp = big;
        big = low;
        low = big;
        for (i = 0; i<big-low; i++)
        {
            printf("%c", right[i]);
        }
        for (j = 0; j<low; j++)
        {
            if (right[i] == '1' || left[j] == '1')
                printf("1");
            else printf("0");
            i++;
        }
    }
    else 
    {
        for (i = 0; i<big-low; i++)
        {
            printf("%c", left[i]);
        }
        for (j = 0; j<low; j++)
        {
            if (left[i] == '1' || right[j] == '1')
                printf("1");
            else printf("0");
            i++;
        }
    }
    printf("\n");
}

void xorr(char * left , char * right)
{
    int i, j;
    int temp;
    int big = strlen(left);
    int low = strlen(right);;
    printf("%s ^ %s = ", left, right);
    if (big<low)
    {
        temp = big;
        big = low;
        low = big;
        for (i = 0; i<big-low; i++)
        {
            printf("%c", right[i]);
        }
        for (j = 0; j<low; j++)
        {
            if (right[i] != left[j])
                printf("1");
            else printf("0");
            i++;
        }
    }
    else 
    {
        for (i = 0; i<big-low; i++)
        {
            printf("%c", left[i]);
        }
        for (j = 0; j<low; j++)
        {
            if (left[i] != right[j])
                printf("1");
            else printf("0");
            i++;
        }
    }
}
