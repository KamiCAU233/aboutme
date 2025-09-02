#include <stdio.h>

int main()
{
    int max = -1e9;
    int maxRow = -1;
    int maxColumn = -1;
    int matrix[4][3];
    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            scanf("%d", &matrix[r][c]);
            if (matrix[r][c] > max)
            {
                max = matrix[r][c];
                maxRow = r;
                maxColumn = c;
            }
        }
    }
    printf("max=%d\nrow=%d,col=%d\n", max, maxRow, maxColumn);
}
