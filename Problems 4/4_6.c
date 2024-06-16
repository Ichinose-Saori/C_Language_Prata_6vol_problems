#include <stdio.h>
#include <string.h>
#include <stddef.h>

int main()
{
    char name[40];
    char surname[40];
    printf("Please, enter your name and surname.\n");
    scanf("%s %s", name, surname);
    printf("%s %s\n", name, surname);
    printf("%*zd %*zd\n", strlen(name), strlen(name), strlen(surname), strlen(surname));
    printf("%s %s\n", name, surname);
    printf("%-*zd %-*zd\n", strlen(name), strlen(name), strlen(surname), strlen(surname));
    return 0;
}
