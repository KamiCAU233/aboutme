#include <stdio.h>

double getTotal(int n);
double getBounce(int n);

int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("error");
        return -1;
    }
    printf("%.2lf\n%.2lf\n", getTotal(n), getBounce(n));
}

// n = 1; x = 150; s = 50;
// n = 2; x = 100 + 2 * 50;

double getBounce(int n)
{
    if (n == 0)
    {
        return 100;
    }
    return (getBounce(n - 1) / 2.0);
}

double getTotal(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 100;
    }
    return getTotal(n - 1) + 2 * getBounce(n - 1);
}
