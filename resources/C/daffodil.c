#include <stdio.h>

int cube(int a);

int main()
{
    for (int n = 100; n < 1000; n++)
    {
        int a = n % 10;
        int b = n / 10 % 10;
        int c = n / 100;
        if (cube(a) + cube(b) + cube(c) == n)
        {
            printf("%i ", n);
        }
    }
    printf("\n");
}

int cube(int a)
{
    return a * a * a;
}
