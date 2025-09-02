#include <stdio.h>

int fraction(int n);
int getSum(int n);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%i\n", getSum(n));
}

int getSum(int n)
{
    switch (n)
    {
        case 0:
        {
            return 0;
            break;
        }
        case 1:
        {
            return 1;
            break;
        }
        default:
        {
            return fraction(n) + getSum(n - 1);
            break;
        }
    }
    return -1;
}

int fraction(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return fraction(n - 1) * n;
}
