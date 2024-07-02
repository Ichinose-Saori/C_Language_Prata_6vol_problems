#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 5

void print_arr(double(*arr)[COLS], int rows);
void enter_n(double* arr, int cols);
double avg_row(double* arr, int cols);
double avg_all(double(*arr)[COLS], int rows);
double king_of_array(double(*arr)[COLS], int rows);

int main(void)
{
    double source[ROWS][COLS];
    for (int i = 0; i < ROWS; i++)
    {
        enter_n(source[i], COLS);
    }
    print_arr(source, ROWS);
    for (int i = 0; i < ROWS; i++)
    {
        printf("Average of row %d is %lf.\n", i, avg_row(source[i], COLS));
    }
    printf("\nAverage of array is %lf.\n\n", avg_all(source, ROWS));
    printf("The king of my array is %lf.\n", king_of_array(source, ROWS));
    return 0;
}

void enter_n(double* arr, int cols)
{
    /* for (int i = 0; i<cols; i++)
         scanf("%lf", &arr[i]);
         */
    for (int i = 0; i < cols; i++)
        arr[i] = rand();
}

double avg_row(double* arr, int cols)
{
    double sum = 0;
    for (int i = 0; i < cols; i++)
        sum += arr[i];
    return sum / cols;
}

double avg_all(double(*arr)[COLS], int rows)
{
    double sum=0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
            sum += arr[i][j];
    }
    return sum / (COLS * rows);
}

void print_arr(double(*arr)[COLS], int rows)
{
    printf("I'll show you my array!\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%8.1lf ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

double king_of_array(double(*arr)[COLS], int rows)
{
    double max = arr[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (arr[i][j] > max) max = arr[i][j];
        }
    }
    return max;
}
