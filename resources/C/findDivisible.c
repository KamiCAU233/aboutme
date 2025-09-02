#include <stdio.h>

int main()
{
    int array[20];
    for (int i = 0; i < 20; i++)
    {
        scanf("%d", &array[i]);
    }
    for (int j = 0; j < 20; j++)
    {
        for (int k = 0; k < 20; k++)
        {
            if (array[j] % array[k] == 0 && k != j)
            {
                printf("%i ", array[j]);
                break;
            }
        }
    }
    printf("\n");
}
