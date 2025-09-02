#include <stdio.h>

int main()
{
    int m, n;
    scanf("%i%i", &m, &n);
    int fac = m;
    while (fac > 1)
    {
        if (m % fac == 0 && n % fac == 0)
        {
            break;
        }
        fac--;
    }
    int mul = m * n / fac;
    printf("%i %i", fac, mul);
}
