#include <stdio.h>

int main()
{
    int a, b, r;
    scanf("%d%d", &a, &b);
    if (a * a + b * b > 100)
    {
        r = (a * a + b * b) / 100;
    }
    else
    {
        r = a + b;
    }
    printf("%d\n", r);
}
