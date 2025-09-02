#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int row;
    int column;
    int msq[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            msq[i][j] = 0;
        }
    }
    for (int i = 0; i < n * n; i++)
    {
        if (i == 0)
        {
            row = 0;
            column = n / 2;
        }
        msq[row][column] = i + 1;
        if (row == 0)
        {
            if (column == n - 1)
            {
                row++;
            }
            else
            {
                row = n - 1;
                column++;
            }
        }
        else if (column == n - 1)
        {
            row--;
            column = 0;
        }
        else if (msq[row - 1][column + 1] != 0)
        {
            row++;
        }
        else
        {
            row--;
            column++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", msq[i][j]);
            if (j != n - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
