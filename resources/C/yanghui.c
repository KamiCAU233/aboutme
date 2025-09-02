#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int row[100][100] = {{0}};
    for (int i = 0; i < n; i++)
    {
        row[i][0] = 1;
        row[i][i] = 1;
    }
    for (int ii = 0; ii < n; ii++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ii != 0 && j != 0)
            {
                row[ii][j] = row[ii - 1][j - 1] + row[ii - 1][j];
            }
        }
    }
    for (int iii = 0; iii < n; iii++)
    {
        for (int j = 0; j <= iii; j++)
        {
            printf("%d", row[iii][j]);
            if (j != iii)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
