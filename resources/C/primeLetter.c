#include <stdio.h>
#include <math.h>

int isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char x;
    scanf("%c", &x);
    if (isPrime((int)x))
    {
        printf("%c is a prime letter!\n", x);
    }
    else
    {
        printf("%c is not a prime letter!\n", x);
    }
}
