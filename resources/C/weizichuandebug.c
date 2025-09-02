#include <stdio.h>
#include <stdlib.h>

#define N 1000000
int main()
{
    int x1, x2, y1, y2, m, n, a, b, c, d, i, s, y, z, sum;
    i = 1;
    s = 1;
    sum = 0;
    scanf("%d %d\n%d %d\n%d\n%d", &x1, &y1, &x2, &y2, &n, &m);
    while (i <= N)
    {
        a = x1, b = y1, c = x2, d = y2;
        i++;
        while (s <= n)
        {
            s++;
            y = rand() % (a + b) + 1;
            if (y <= a)
            {
                a = a - 1;
            }
            else
            {
                b = b - 1;
            }
        }
        s = 1;
        while (s <= n)

        {

            z = rand() % (c + d) + 1;
            if (z <= c)
            {
                c = c - 1;
                a = a + 1;
            }

            else
            {
                d = d - 1;
            }
            s++;
        }
        if (a == m)
        {
            sum++;
        }
    }
    printf("%.2lf", 1.0 * sum / N);
}
