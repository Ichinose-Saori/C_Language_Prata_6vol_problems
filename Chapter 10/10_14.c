#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 5

void print_arr(int rows, int cols, double arr[rows][cols]);
void enter_n(int cols, double arr[cols]);
double avg_row(int cols, double arr[cols]);
double avg_all(int rows, int cols, double arr[rows][cols]);
double king_of_array(int rows, int cols, double arr[rows][cols]);

int main(void)
{
    double source[ROWS][COLS];
    for (int i = 0; i < ROWS; i++)
    {
        enter_n(COLS, source[i]);
    }
    print_arr(ROWS, COLS, source);
    for (int i = 0; i < ROWS; i++)
    {
        printf("Average of row %d is %lf.\n", i, avg_row(COLS, source[i]));
    }
    printf("\nAverage of array is %lf.\n\n", avg_all(ROWS, COLS, source));
    printf("The king of my array is %lf.\n", king_of_array(ROWS, COLS, source));
    return 0;
}

void enter_n(int cols, double arr[cols])
{
    /* for (int i = 0; i<cols; i++)
         scanf("%lf", &arr[i]);
         */
    for (int i = 0; i < cols; i++)
        arr[i] = rand();
}

double avg_row(int cols, double arr[cols])
{
    double sum = 0;
    for (int i = 0; i < cols; i++)
        sum += arr[i];
    return sum / cols;
}

double avg_all(int rows, int cols, double arr[rows][cols])
{
    double sum=0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            sum += arr[i][j];
    }
    return sum / (COLS * rows);
}

void print_arr(int rows, int cols, double arr[rows][cols])
{
    printf("I'll show you my array!\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%8.1lf ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

double king_of_array(int rows, int cols, double arr[rows][cols])
{
    double max = arr[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] > max) max = arr[i][j];
        }
    }
    return max;
}
