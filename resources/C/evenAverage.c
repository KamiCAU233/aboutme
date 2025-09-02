#include <stdio.h>

int main()
{
    int even[30];
    for (int i = 0; i < 30; i++)
    {
        even[i] = 2 * i + 2;
    }
    int avg[6];
    for (int j = 0; j < 6; j++)
    {
        int sum = 0;
        for (int k = 0; k < 5; k++)
        {
            sum = sum + even[j * 5 + k];
        }
        avg[j] = sum / 5;
    }

    for (int t = 0; t < 30; t++)
    {
        printf("%d", even[t]);
    }
    printf("\n");
    for (int tt = 0; tt < 6; tt++)
    {
        printf("%d", avg[tt]);
    }
    printf("\n");
}


