#include <stdio.h>
#include <string.h>

int main()
{
    char array[100];
    scanf("%s", array);
    printf("\"%s\"\n", array);
    printf("\"%20s\"\n", array);
    printf("\"%-20s\"\n", array);
    printf("%*s\n", strlen(array)+3, array);

    return 0;
}
