#include <stdio.h>

void infect(char room[100][100], int n);
int main()
{
    int n, m;
    scanf("%d", &n);
    char room[100][100];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", room[i]);
    }
    scanf("%d", &m);
    for (int j = 1; j < m; j++)
    {
        infect(room, n);
    }
    int count = 0;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            if (room[x][y] == '@')
            {
                count++;
            }
        }
    }
    printf("%d\n", count);
}

void infect(char room[100][100], int n)
{
    char new_infected[100][100] = {{'0'}};
    // Check all the old infecters
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (room[i][j] == '@')
            {
                // UP:
                if (i != 0)
                {
                    if (room[i - 1][j] == '.')
                    {
                        new_infected[i - 1][j] = '@';
                    }
                }
                // DOWN:
                if (i != n - 1)
                {
                    if (room[i + 1][j] == '.')
                    {
                        new_infected[i + 1][j] = '@';
                    }
                }
                // LEFT:
                if (j != 0)
                {
                    if (room[i][j - 1] == '.')
                    {
                        new_infected[i][j - 1] = '@';
                    }
                }
                // RIGHT:
                if (j != n - 1)
                {
                    if (room[i][j + 1] == '.')
                    {
                        new_infected[i][j + 1] = '@';
                    }
                }
            }
        }
    }
    // Update the newly-infected residents
    for (int p = 0; p < n; p++)
    {
        for (int q = 0; q < n; q++)
        {
            if (new_infected[p][q] == '@')
            {
                room[p][q] = '@';
            }
        }
    }
}
