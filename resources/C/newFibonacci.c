#include <stdio.h>

int newFibonacci(int n);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%i\n", newFibonacci(n));
}

int newFibonacci(int n)
{
    if (n == 1 || n == 2 || n == 3)
    {
        return 1;
    }
    else
    {
        return newFibonacci(n - 1) + newFibonacci(n - 2) + newFibonacci(n - 3);
    }
}
