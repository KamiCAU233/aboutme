#include <stdio.h>

int sum(int x[3][3]);

int main()
{
    int matrix[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("%d\n", sum(matrix));
}

int sum(int x[3][3])
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += x[i][i];
    }
    for (int j = 0; j < 3; j++)
    {
        sum += x[j][2 - j];
    }
    return sum - x[1][1];
}
