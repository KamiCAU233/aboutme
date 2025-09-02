#include <stdio.h>
#include <math.h>

int main()
{
    int yy, mm, dd;
    scanf("%d%d%d", &yy, &mm, &dd);
    int date = yy * 10000 + mm * 100 + dd;
    int t = 2;
    char isPrime = 'y';
    while (sqrt(date) >= t)
    {
        if (date % t == 0)
        {
            isPrime = 'n';
        }
        t++;
    }
    printf("%c\n", isPrime);
}
