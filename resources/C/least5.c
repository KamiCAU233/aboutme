#include <stdio.h>

int main()
{
    int x[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", x + i);
    }
    for (int j = 0; j < 10; j++)
    {
        for (int k = 0; k < 10; k++)
        {
            if (x[k] > x[j] && k < j)
            {
                int temp = x[k];
                x[k] = x[j];
                x[j] = temp;
            }
        }
    }
    int sum = 0;
    for (int p = 0; p < 5; p++)
    {
        sum = sum + x[p];
    }
    printf("%d\n", sum);
}
