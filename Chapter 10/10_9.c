#include <stdio.h>

#define ROWS 3
#define COLS 5

void copy_VLA(int rows, int cols, const double source[rows][cols], double target[rows][cols]);

int main(void)
{
    double source[ROWS][COLS] = {
    {1.0, 2.0, 3.0, 4.0, 5.0},
    {6.0, 7.0, 8.0, 9.0, 10.0},
    {11.0, 12.0, 13.0, 14.0, 15.0}
    };
    double target[ROWS][COLS];
    copy_VLA(ROWS, COLS, source, target);
    printf("This is SOURCE:\n");
    print_VLA(ROWS, COLS, source);
    printf("\nThis is TARGET:\n");
    print_VLA(ROWS, COLS, target);

    return 0;
}

void copy_VLA(int rows, int cols, const double source[rows][cols], double target[rows][cols])
{
    for (int i = 0; i<rows; i++)
    {
        for (int j = 0; j<cols; j++)
        {
            target[i][j] = source[i][j];
        }
    }
}

void print_VLA(int rows, int cols, const double source[rows][cols])
{
    for (int i = 0; i<rows; i++)
    {
        for (int j = 0; j<cols; j++)
        {
            printf("%4.1lf ", source[i][j]);
        }
        printf("\n");
    }
}
