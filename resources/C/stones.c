#include <stdio.h>

int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int m = 0; m < 10; m++)
    {
        for (int n = 0; n < 10; n++)
        {
            if (arr[m] > arr[n] && m < n)
            {
                int temp = arr[m];
                arr[m] = arr[n];
                arr[n] = temp;
            }
        }
    }
    int count = 0;
    int weight = 0;
    while (weight <= 20)
    {
        weight = weight + arr[count];
        count++;
    }
    if (count == 0)
    {
        return -1;
    }
    printf("%i\n", count - 1);
}
