#include <stdio.h>

int fibonacci(int n);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%i\n", fibonacci(n));
}

int fibonacci(int n)
{
    if(n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
