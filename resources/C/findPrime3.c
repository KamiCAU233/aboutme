#include <stdio.h>
#include <math.h>

int isPrime(int n);

int main()
{
    int a, b;
    int count = 0, sum = 0;
    scanf("%d%d", &a, &b);
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    for (int i = a; i < b + 1; i++)
    {
        if (isPrime(i))
        {
            count++;
            sum += i;
        }
    }
    printf("%d\n", count);
}

int isPrime(int n)
{
    if (n == 1)
    {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
