#include <stdio.h>

int main()
{
    int row, column, mineCount;
    scanf("%d %d%d", &row, &column, &mineCount);
    int map[row][column];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            map[i][j] = 0;
        }
    }

    for (int i = 0; i < mineCount; i++)
    {
        int position;
        scanf("%d", &position);
        int y;
        if ((position + 1) % column == 0)
        {
            y = (position + 1) / column - 1;
        }
        else
        {
            y = (position + 1) / column;
        }
        int x = position - column * y;


        map[x][y] = -1;

        if (map[x - 1][y] != -1 && x != 0)
        {
            map[x - 1][y]++;
        }
        if (map[x + 1][y] != -1 && x != row - 1)
        {
            map[x + 1][y]++;
        }
        if (map[x][y - 1] != -1 && y != 0)
        {
            map[x][y - 1]++;
        }
        if (map[x][y + 1] != -1 && y != column - 1)
        {
            map[x][y + 1]++;
        }
        if (map[x + 1][y + 1] != -1 && x != row - 1 && y != column - 1)
        {
            map[x + 1][y + 1]++;
        }
        if (map[x + 1][y - 1] != -1 && x != row - 1 && y != 0)
        {
            map[x + 1][y - 1]++;
        }
        if (map[x - 1][y + 1] != -1 && x != 0 && y != column - 1)
        {
            map[x - 1][y + 1]++;
        }
        if (map[x - 1][y - 1] != -1 && x != 0 && y != 0)
        {
            map[x - 1][y - 1]++;
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%i", map[j][i]);
            if (j != column - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
