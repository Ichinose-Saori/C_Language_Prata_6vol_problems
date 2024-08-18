#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLS 31

void translate(char arr[][COLS], int, int);
void error_correction(char arr[][COLS], int, int);

int main(void)
{
    FILE* fp;
    int n = 20, m = COLS;
    char ch;
    //scanf("%d", &n);
    //scanf("%d", &m);
    char arr[n][m];
    
    if ((fp = fopen("a.txt", "r")) == NULL)
    {
        fprintf(stderr, "Failed to open \"a.txt\"");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j<m; j++)
        {
            while ((ch = getc(fp)) <'0' || ch > '9')
                continue;
            arr[i][j] = ch;
        }
    }
    error_correction(arr, n, m);
    translate(arr, n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j<m; j++)
        {
            putchar(arr[i][j]);
        }
        putchar('\n');
    }
    
    if(fclose(fp) != 0)
    {
        fprintf(stderr, "Failed to close \"a.txt\"");
        exit(EXIT_FAILURE);
    }

    return 0;
}

void translate (char arr[][COLS], int rows, int cols)
{
    for (int i = 0; i<rows; i++)
    {
        for (int j = 0; j<cols; j++)
        {
            switch(arr[i][j])
            {
                case '0':
                    arr[i][j] = ' ';
                    break;
                case '1':
                    arr[i][j] = '.';
                    break;
                case '2':
                    arr[i][j] = '\'';
                    break;
                case '3':
                    arr[i][j] = ':';
                    break;
                case '4':
                    arr[i][j] = '~';
                    break;
                case '5':
                    arr[i][j] = '*';
                    break;
                case '6':
                    arr[i][j] = '=';
                    break;
                case '7':
                    arr[i][j] = '&';
                    break;
                case '8':
                    arr[i][j] = '%';
                    break;
                case '9':
                    arr[i][j] = '#';
                    break;
            }
        }
    }
}

void error_correction(char arr[][COLS], int rows, int cols)
{
    for (int i = 1; i<rows-1; i++)
    {
        for (int j = 1; j<cols-1; j++)
        {
            if (arr[i][j] - arr[i][j-1] > 1 && arr[i][j] - arr[i][j+1] >1 && arr[i][j] - arr[i+1][j] >1 && arr[i][j] - arr[i-1][j] >1)
                arr[i][j] = (int)((arr[i][j-1]+arr[i][j+1]+arr[i+1][j]+arr[i-1][j])/4);
        }
    }
    for (int i = 0; i<rows; i++)
    {
        if (i == 0)
        {
            if (arr[i][0] - arr[i+1][0] > 1 && arr[i][0] - arr[i][1] > 1)
                arr[i][0] = (int)((arr[i+1][0] + arr[i][1])/2);
            if (arr[i][29] - arr[i+1][29] > 1 && arr[i][29] - arr[i][28] > 1)
                arr[i][29] = (int)((arr[i+1][29] + arr[i][28])/2);
        }
        else if (i == 19)
        {
            if (arr[i][0] - arr[i][1] >1 && arr[i][0] - arr[i-1][0] > 1)
                arr[i][0] = (int)((arr[i][1] + arr[i-1][0])/2);
            if (arr[i][29] - arr[i][28] >1 && arr[i][29] - arr[i-1][29])
                arr[i][29] = (int)((arr[i][28] + arr[i-1][29])/2);
        }
        else
        {
            if (arr[i][0] - arr[i][1] > 1 && arr[i][0] - arr[i-1][0] > 1 && arr[i][0] - arr[i+1][0])
                arr[i][0] = (int)((arr[i][1] + arr[i-1][0] + arr[i+1][0])/3);
            if (arr[i][29] - arr[i+1][29] > 1 && arr[i][29] - arr[i-1][29] > 1 && arr[i][29] - arr[i][28] > 1)
                arr[i][29] = (int)((arr[i+1][29] + arr[i-1][29] + arr[i][28])/3);
        }
    }
    for (int j = 1; j<29; j++)
    {
        if (arr[0][j] - arr[0][j-1] > 1 && arr[0][j] - arr[0][j+1] > 1 && arr[0][j] - arr[1][j] >1)
            arr[0][j] = (int)((arr[0][j-1] + arr[0][j+1] + arr[1][j])/3);
        if (arr[19][j] - arr[19][j-1] > 1 && arr[19][j] - arr[19][j+1] > 1 && arr[19][j] - arr[18][j] > 1)
            arr[19][j] = (int)((arr[19][j-1] + arr[19][j+1] + arr[18][j])/3);
    }
}