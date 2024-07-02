#include <stdio.h>
#define SIZE 10

double difference_BL(const double *, int);

int main(void)
{
    double arr[SIZE] = {1.2, -12123.3, -43.0};
    printf("The difference is %lf.\n", difference_BL(arr, SIZE));
    return 0;
}

double difference_BL(const double * arr, int len)
{
    double big = arr[0];
    double least = arr[0];
    for (int i = 0; i<len; i++)
    {
        if (arr[i]>big)
            big = arr[i];
        else if (arr[i]<least)
            least = arr[i];
    }
    return big - least;
}
