#include <stdio.h>

int main()
{
    int a[15];
    int frequency[1000] = {0};
    for (int i = 0; i < 15; i++)
    {
        scanf("%d", &a[i]);
        frequency[a[i]]++;
    }
    int max = 0;
    for (int j = 0; j < 15; j++)
    {
        if (frequency[a[j]] > max)
        {
            max = frequency[a[j]];
        }
    }
    for (int p = 0; p < 1000; p++)
    {
        if (frequency[p] == max)
        {
            printf("%d ", p);
        }
    }
    printf("\n");
}
