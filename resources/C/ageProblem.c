#include <stdio.h>

int getAge(int n);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%i\n", getAge(n));
}

int getAge(int n)
{
    if (n == 1)
    {
        return 10;
    }
    else
    {
        return getAge(n - 1) + 2;
    }
}
