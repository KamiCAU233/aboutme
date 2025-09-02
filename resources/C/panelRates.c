#include <stdio.h>

int main()
{
    double rates[9];
    double min = 1e9;
    double max = -1e9;
    for (int i = 0; i < 9; i++)
    {
        scanf("%lf", &rates[i]);
        if (rates[i] <= min)
        {
            min = rates[i];
        }
        if (rates[i] >= max)
        {
            max = rates[i];
        }
    }
    double sum = 0;
    int count = 0;
    for (int j = 0; j < 9; j++)
    {
        if (rates[j] != max && rates[j] != min)
        {
            sum = sum + rates[j];
            count++;
        }
    }
    printf("High:%.2f\nLow:%.2f\nAverage:%.2f\n", max, min, 1.0 * sum / count);
}
