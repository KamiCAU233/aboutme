#include <stdio.h>

int isPrime(int n);

int main()
{
    for (int i = 100; i < 501; i++)
    {
        if(isPrime(i))
        {
            printf("%i\n", i);
        }
    }
}

int isPrime(int n)
{
    for (int x = 2; x * x <= n; x++)
    {
        if (n % x == 0)
        {
            return 0;
        }
    }
    return 1;
}
