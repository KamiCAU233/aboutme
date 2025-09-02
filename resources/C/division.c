#include <stdio.h>

int main()
{
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    int b[9];
    for (int j = 0; j < 9; j++)
    {
        b[j] = a[j + 1] / a[j];
    }
    for (int k = 0; k < 9; k++)
    {
        printf("%3d", b[k]);
        if (k % 3 == 2)
        {
            printf("\n");
        }
    }
}
