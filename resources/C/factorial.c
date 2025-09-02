#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);
    int mul = 1;
    for (int i = 1; i <= x ; i++)
    {
        mul = mul * i;
    }
    printf("%i\n", mul);
}
