#include <stdio.h>
#include <string.h>

int main()
{
    printf("Please, enter your download speed in m/bit and files size in m/bytes.\n");
    float dSpeed=0, size=0;
    scanf("%f %f", &dSpeed, &size);
    printf("With the download speed %.2f megabits p.s. and file size of %.2f megabytes\nIt will take %.2f seconds.", dSpeed, size, size*8/dSpeed);
    return 0;
}
