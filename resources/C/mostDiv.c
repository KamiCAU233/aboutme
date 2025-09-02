#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int mostDiv = 0;
    int initial = a;
    while (a <= b)
    {
        int div = 0;
        for (int i = 1; i <= a; i++)
        {
            if (a % i == 0)
            {
                div++;
            }
        }
        if (div > mostDiv)
        {
            mostDiv = div;
        }
        a++;
    }
    a = initial;
    while (a <= b)
    {
        int div = 0;
        for (int i = 1; i <= a; i++)
        {
            if (a % i == 0)
            {
                div++;
            }
        }
        if (div == mostDiv)
        {
            printf("%i %i\n", a, mostDiv);
        }
        a++;
    }
}
