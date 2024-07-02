#include <stdio.h>

#define ROWS 2
#define COLS 3

void copy_arr(const double (*orig)[COLS], double (*target)[COLS], int rows);

int main(void)
{
    double orig[2][3] =
    {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0}
    };
    double target[2][3];
    copy_arr(orig, target, ROWS);
    for (int i = 0; i<ROWS; i++)
    {
        for (int j = 0; j<COLS; j++)
        {
            printf("%lf ", target[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void copy_arr(const double (*orig)[COLS], double (*target)[COLS], int rows)
{
    for (int i = 0; i<rows; i++)
    {
        for (int j = 0; j<COLS; j++)
        {
            target[i][j] = orig[i][j];
        }
    }
}
