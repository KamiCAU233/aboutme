#include <stdio.h>
#include <math.h>

int getFibonacci(int n);
int isFibonacci(int n);
int isPrime(int n);

int main()
{
    int n;
    scanf("%d", &n);
    if (n > 30000)
    {
        n = 30000;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (isPrime(i))
        {
            if (isFibonacci(i))
            {
                count++;
            }
        }
    }
    printf("%d\n", count);
}

int isFibonacci(int n)
{
    int t;
    if (n < 20)
    {
        t = 100;
    }
    else if (n > 10000)
    {
        t = sqrt(n);
    }
    else t = n;
    for (int i = 0; i < t; i++)
    {
        int x = getFibonacci(i);
        if (x == n)
        {
            return 1;
        }
        else if (x > n)
        {
            return 0;
        }
    }
    return 0;
}

int isPrime(int n)
{
    if (n == 1) return 0;
    int t = sqrt(n);
    for (int i = 2; i <= t; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int getFibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return (getFibonacci(n - 1) + getFibonacci(n - 2));
}

