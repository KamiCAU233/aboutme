#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a = n / 1000;
    int b = n / 100 - 10 * a;
    int c = n / 10 - 10 * (n / 100);
    int d = n - 10 * (n / 10);
    printf("%d %d %d %d\n", a, b, c, d);
}
