#include <stdio.h>

int main()
{
    int even[2][3];
    for (int r = 0; r < 2; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            even[r][c] = 2 * (r * 3 + c + 1);
        }
    }
    for (int rr = 0; rr < 2; rr++)
    {
        for (int cc = 0; cc < 3; cc++)
        {
            printf("%4d", even[rr][cc]);
        }
        printf("\n");
    }
    for (int rrr = 0; rrr < 3; rrr++)
    {
        for (int ccc = 0; ccc < 2; ccc++)
        {
            printf("%4d", even[ccc][rrr]);
        }
        printf("\n");
    }
}
