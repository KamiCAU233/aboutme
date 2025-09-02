#include <stdio.h>

int main()
{
    int n;
    double bill = 0;
    scanf("%d", &n);
    if (n <= 240)
    {
        bill = n * 0.53;
    }
    else if (n <= 400)
    {
        bill = (n -  240) * 0.58 + 240 * 0.53;
    }
    else if (n >= 400)
    {
        bill = 240 * 0.53 + 160 * 0.58 + (n - 400) * 0.83;
    }
    printf("%.2f\n", bill);
}
