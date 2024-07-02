#include <stdio.h>

#define ROWS 3
#define COLS 5

void print_VLA(int rows, int cols, const double source[rows][cols]);
void sum_arrVLA(int rows, int cols, const double arr1[rows][cols], const double arr2[rows][cols], double target[rows][cols]);

int main(void)
{
    double arr_a[ROWS][COLS];
    double arr_b[ROWS][COLS];
    for (int i = 0; i<ROWS; i++)
    {
        for (int j = 0; j<COLS; j++)
        {
            arr_a[i][j] = 1.0;
            arr_b[i][j] = 2.0;
        }
    }
    int arr_sum[ROWS][COLS];
    sum_arrVLA(ROWS, COLS, arr_a, arr_b, arr_sum);
    print_VLA(ROWS, COLS, arr_sum);
    return 0;
}


void print_VLA(int rows, int cols, const double source[rows][cols])
{
    for (int i = 0; i<rows; i++)
    {
        for (int j = 0; j<cols; j++)
        {
            printf("%lf ", source[i][j]);
        }
        printf("\n");
    }
}

void sum_arrVLA(int rows, int cols, const double arr1[rows][cols], const double arr2[rows][cols], double target[rows][cols])
{
    for (int i = 0; i<rows; i++)
    {
        for (int j = 0; j<cols; j++)
        {
            target[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}
