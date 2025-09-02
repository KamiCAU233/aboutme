#include <stdio.h>

int getFraction(int n);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%i\n", getFraction(n));
}

int getFraction(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    else
    {
        return getFraction(n - 1) * n;
    }
    return 0;
}
