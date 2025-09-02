#include <math.h>
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int num = n;
    int counter = 1;
    while (n / 10 > 0)
    {
        n = n / 10;
        counter++;
    }
    printf("%i\n", counter);
    int c = counter;
    for (int i = 0; i < c; i++)
    {
        int j = (int) (num / pow(10, counter - 1)) - (10 * (int) (num / pow(10, counter)));
        printf("%i", j);
        counter = counter - 1;
        if (i < c - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
    int reversedNumber = 0;
    while (num != 0)
    {
        reversedNumber = reversedNumber * 10 + num % 10;
        num = num / 10;
    }
    printf("%i\n", reversedNumber);
}
