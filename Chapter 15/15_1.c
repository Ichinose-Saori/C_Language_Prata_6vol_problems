#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define LEN 80

char* s_gets(char*, int);

int main(void)
{
    int length;
    long long sum = 0;
    long long two_pow = 1;
    char arr[LEN];
    puts("Enter your binary number:");
    s_gets(arr, LEN);
    length = strlen(arr);
    for (int i = length - 1; i > 0; i--)
    {
        sum += two_pow * (arr[i] - '0');
        two_pow *= 2;
    }
    printf("Your number is %lld\n", sum);
    return 0;
}

char* s_gets(char* word, int len)
{
    char* ret_val;
    char* find;
    ret_val = fgets(word, len, stdin);
    if (ret_val)
    {
        find = strchr(word, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
