#include <stdio.h>

int main()
{
    int n, time;
    int arr[100] = {0};
    scanf("%d%d", &n, &time);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int j = 0; j < time; j++)
    {
        for (int p = 99; p > 0; p--)
        {
            arr[p] = arr[p - 1];
        }
    }
    for (int q = 0; q < time; q++)
    {
        arr[q] = arr[n + q];
    }
    for (int z = 0; z < n; z++)
    {
        printf("%i ", arr[z]);
    }
}
