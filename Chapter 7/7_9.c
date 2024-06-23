#include <stdio.h>
#include <string.h>

int main()
{
    int num_main;
    int flag;
    printf("Hello! This program will give you all prime numbers less than or equal to yours.\n");
    while((scanf("%d", &num_main)) != 1)
    {
        printf("Don't enter any NONINTEGER value and try again!\n");
        getchar();
    }
    for (int i = 2; i<=num_main; i++)
    {
        flag = 0;
        for (int j=2; j*j<=i; j++)
        {
            if (i%j==0)
            {
                flag = 1;
                break;
            }
        }
        if (!flag) printf("%d\n", i);
    }
    return 0;
}
