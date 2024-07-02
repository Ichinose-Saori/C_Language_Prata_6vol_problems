#include <stdio.h>

#define ROWS 3
#define COLS 5

void print(const double (*source)[COLS], int rows);
void init_arr(double (*arr)[COLS], int rows);
void double_arr(double (*arr)[COLS], int rows);

int main(void)
{
    double arr[ROWS][COLS];
    init_arr(arr, ROWS);
    printf("Array before manipulation.\n\n");
    print(arr, ROWS);
    double_arr(arr, ROWS);
    printf("Array after manipulation.\n\n");
    print(arr, ROWS);
    return 0;
}


void print(const double (*source)[COLS], int rows)
{
    for (int i = 0; i<rows; i++)
    {
        for (int j = 0; j<COLS; j++)
        {
            printf("%5.1lf ", source[i][j]);
        }
        printf("\n");
    }
}

void double_arr(double (*arr)[COLS], int rows)
{
    for (int i = 0; i<rows; i++)
    {
        for (int j = 0; j<COLS; j++)
        {
            arr[i][j] *=2;
        }
    }
}

void init_arr(double (*arr)[COLS], int rows)
{
    for (int i = 0; i<rows; i++)
    {
        for (int j = 0; j<COLS; j++)
        {
           //scanf("%lf", &arr[i][j]);
           arr[i][j] = (double)(i+1)*(j+1);
        }
    }
}
