#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 500000

int sequence(int a, int b, int c);

int main()
{
    srand(time(NULL));
    int sequences[13] = {840, 831, 822, 750, 741, 732, 660, 651, 642, 633, 552, 444, 543};
    int prizes[13] = {100, 10, 10, 20, 2, 2, 20, 1, 1, 1, 1, 1, -10};
    int prize = 0;
    int counter = 0;
    for (int i = 0; i < N; i++)
    {
        int blue = 0;
        int red = 0;
        int yellow = 0;
        for (int j = 0; j < 12; j++)
        {
            int ran = rand() % 3 + 1;
            if (ran == 1)
            {
                blue++;
            }
            else if (ran == 2)
            {
                red++;
            }
            else
            {
                yellow++;
            }
        }
        int sorted = sequence(blue, red, yellow);
        for (int k = 0; k < 13; k++)
        {
            if (sorted == sequences[k])
            {
                prize = prize + prizes[k];
                counter++;
            }
        }
    }
    printf("%.2f\n", 1.0 * prize / counter);
}

int sequence(int a, int b, int c)
{
    int m, n, max, min, mid;
    if (a >= b && a >= c)
    {
         max = a;
         m = b;
         n = c;
    }
    else if (b >= a && b >= c)
    {
         max = b;
         m = a;
         n = c;
    }
    else
    {
         max = c;
         m = a;
         n = b;
    }
    if (m > n)
    {
         min = n;
         mid = m;
    }
    else
    {
         min = m;
         mid = n;
    }
    return (max * 100 + mid * 10 + min);
}
