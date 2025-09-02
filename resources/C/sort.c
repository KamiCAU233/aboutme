#include <stdio.h>

int main()
{
    double array[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%lf", &array[i]);
    }
    for (int j = 0; j < 9; j++)
    {
        for (int k = 0; k < 9; k++)
        {
            if (array[k] > array[k + 1])
            {
                double tmp = array[k + 1];
                array[k + 1] = array[k];
                array[k] = tmp;
            }
        }
    }
    for (int m = 0; m < 10; m++)
    {
        if ((int)array[m] == array[m])
        {
            printf("%i ", (int)array[m]);
        }
        else
        {
            printf("%lf ", array[m]);
        }
    }
    printf("\n");
}
