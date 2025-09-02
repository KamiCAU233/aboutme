#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 500000

int main()
{
    int times[1001] = {0};
    srand(time(NULL));
    int b[3] = {0};
    int n;
    scanf("%d%d%d%d", &b[0], &b[1], &b[2], &n);
    for (int t = 0; t < N; t++)
    {
        int x = b[0];
        int y = b[1];
        int z = b[2];
        int total = b[0] + b[1] + b[2];
        int ballsGot[3] = {0};
        for (int p = 0; p < n; p++)
        {
            int random_num = rand() % total + 1;
            if (random_num <= x)
            {
                ballsGot[0]++;
                x--;
            }
            else if (random_num <= x + y)
            {
                ballsGot[1]++;
                y--;
            }
            else
            {
                ballsGot[2]++;
                z--;
            }
            total--;
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (ballsGot[i] < ballsGot[j] && i < j)
                {
                    int temp = ballsGot[i];
                    ballsGot[i] = ballsGot[j];
                    ballsGot[j] = temp;
                }
            }
        }
        times[ballsGot[0] * 100 + ballsGot[1] * 10 + ballsGot[2]]++;
    }
    for (int i = 100; i < 1000; i++)
    {
        int hundred = i / 100;
        int ten = i / 10 % 10;
        int one = i % 10;
        if (times[i] != 0)
        {
            double pro = 1.0 * times[i] / N;
            printf("%i_%i_%i : %.2lf\n", hundred, ten, one, pro);
        }
    }
}
