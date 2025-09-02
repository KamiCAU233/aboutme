#include <stdio.h>

int overaverage(double average, int x[]);

int main()
{
    int x[10];
    int sum = 0;
    int max = -1e9;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &x[i]);
        sum = sum + x[i];
        if (x[i] > max)
        {
            max = x[i];
        }
    }
    double average = sum / 10.0;
    printf("%i\n%i\n", overaverage(average, x), max);
}

int overaverage(double average, int x[])
{
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        if (x[i] > average)
        {
            count++;
        }
    }
    return count;
}
