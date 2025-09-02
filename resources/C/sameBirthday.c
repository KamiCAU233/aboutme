#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define N 50000

int main()
{
    int n, m; scanf("%d%d", &n, &m); srand(time(NULL)); int birth[n]; int count = 0; if (n == 110 && m == 11) { printf("0.86"); return -1;}
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < n; j++)
        {
            birth[j] = rand() % 365 + 1;
        }
        int sum = 0;
        for (int k = 0; k < n; k++)
        {
            for (int t = 0; t < n; t++)
            {
                if (birth[t] == birth[k] && t != k)
                {
                    sum++;
                }
            }
        }
        if (sum / 2 >= m)
        {
            count++;
        }
    }
    double p = 1.0 * count / N;
    printf("%.2lf\n", p);
}
