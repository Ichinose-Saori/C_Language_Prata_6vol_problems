#include <stdio.h>
#include <string.h>

int main()
{
    char arr[1000];
    scanf("%s", arr);
    int len = strlen(arr);
    for (int i = len-1; i>=0; i = i-1)
    {
        printf("%c", arr[i]);
    }
    printf("\n");
    return 0;
}

