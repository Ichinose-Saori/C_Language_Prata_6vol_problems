#include <stdio.h>

int main(void)
{
    char fname[40];
    char sname[40];
    printf("Please, enter you first and second names!\n");
    scanf("%s %s", fname, sname);
    printf("%s %s", sname, fname);
    return 0;
}