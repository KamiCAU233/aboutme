#include <stdio.h>

int main()
{
    int array[10];
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        scanf("%i", &array[i]);
        sum = sum + array[i];
    }
    double average = 1.0 * sum / 10;
    int aboveCount = 0;
    for (int j = 0; j < 10; j++)
    {
        if (array[j] > average)
        {
            aboveCount++;
        }
    }
    printf("%i\n", aboveCount);
}
