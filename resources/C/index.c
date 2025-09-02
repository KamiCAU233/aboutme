#include <stdio.h>

int main()
{
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    int copy[10];
    int index[10];
    for (int p = 0; p < 10; p++)
    {
        index[p] = -1;
    }
    for (int j = 0; j < 10; j++)
    {
        copy[j] = a[j];
    }
    int m, n;
    for (m = 0; m < 10; m++)
    {
        for (n = 0; n < 10; n++)
        {
            if (copy[m] > copy[n] && m > n)
            {
                int temp = copy[m];
                copy[m] = copy[n];
                copy[n] = temp;
            }
        }
    }
    // Eliminate repetitive elements in copy[10]
    for (int q = 0; q < 9; q++)
    {
        if (copy[q] == copy[q + 1])
        {
            copy[q + 1] = -1;
        }
    }
    for (m = 0; m < 10; m++)
    {
        for (n = 0; n < 10; n++)
        {
            if (copy[m] > copy[n] && m > n)
            {
                int temp = copy[m];
                copy[m] = copy[n];
                copy[n] = temp;
            }
        }
    }
    int ind = 1;
    for (int w = 0; w < 10; w++)
    {
        for (int k = 0; k < 10; k++)
        {
            if (a[k] == copy[w] && index[k] == -1)
            {
                index[k] = w;
            }
        }
    }
    for (int y = 0; y < 10; y++)
    {
        printf("%d ", a[y]);
    }
    printf("\n");
    // for (int yy = 0; yy < 10; yy++)
    // {
    //     printf("%d ", copy[yy]);
    // }
    // printf("\n");
    for (int yyy = 0; yyy < 10; yyy++)
    {
        printf("%d ", index[yyy] + 1);
    }
    printf("\n");
}
