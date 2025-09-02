#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    if (a * a + b * b > 100)
    {
        printf("%i\n", (a * a + b * b) / 100);
    }
    else
    {
        printf("%i\n", a + b);
    }
}
