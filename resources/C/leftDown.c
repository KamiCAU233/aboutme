#include <stdio.h>

int main()
{
    int a[5][5];
    for (int i = 0; i < 25; i++)
    {
        int row = i / 5;
        int col = i % 5;
        a[row][col] = i + 1;
    }
    for (int j = 0; j < 5; j++)
    {
        for (int k = 0; k < 5; k++)
        {
            if (j >= k)
            {
                printf("%4i", a[j][k]);
            }
        }
        printf("\n");
    }
}
