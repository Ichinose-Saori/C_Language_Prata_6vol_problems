#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLS 31

void translate(int n, int m, char arr[n][m]);
void error_correction(char arr[][COLS], int, int);

int main(void)
{
    FILE* fp;
    char ch;
    int n, m;
    printf("Please, enter n and m:\n");
    scanf("%d", &n);
    scanf("%d", &m);
    char arr[n][m+1];
    
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
    translate(m, m+1, arr);
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

void translate (int rows, int cols, char arr[rows][cols])
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