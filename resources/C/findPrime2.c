#include <stdio.h>
#include <math.h>

int isPrime(int n);
int main()
{
    int a[10];
    int prime[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    int n = 0;
    for (int j = 0; j < 10; j++)
    {
        if (isPrime(a[j]))
        {
            prime[n] = a[j];
            n++;
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int m = 0; m < n; m++)
        {
            if (prime[k] < prime[m] && k > m)
            {
                int tmp = prime[k];
                prime[k] = prime[m];
                prime[m] = tmp;
            }
        }
    }
    if (n == 0)
    {
        printf("No prime\n");
    }
    else for (int t = 0; t < n; t++)
    {
        printf("%i", prime[t]);
        if (t != n)
        {
            printf(" ");
        }
        else printf("\n");
    }
}

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
