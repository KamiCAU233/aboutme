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
    int c = counter;
    int reversedNumber = 0;
    while (num != 0)
    {
        reversedNumber = reversedNumber * 10 + num % 10;
        num = num / 10;
    }
    printf("%i\n", reversedNumber);
}
