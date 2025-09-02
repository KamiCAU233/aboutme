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

int prime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (isPrime(i) && isPrime(n - i))
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n;
    scanf("%d", &n);
    if (n % 2 != 0 || n < 6)
    {
        printf("Input an even num (>=6)\n");
        return 1;
    }
    printf("%i+%i\n", prime(n), n - prime(n));
}
