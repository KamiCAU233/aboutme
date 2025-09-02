#include <cs50.h>
#include <stdio.h>
int sequence(int a, int b, int c);

int main()
{
    int a = get_int("a:");
    int b = get_int("b:");
    int c = get_int("c:");
    printf("%i\n", sequence(a, b, c));
}
int sequence(int a, int b, int c)
{

    int max, m, n, min, mid;
    if (a >= b && a >= c)
    {
        max = a;
        m = b;
        n = c;
    }
    else if (b >= a && b >= c)
    {
        max = b;
        m = a;
        n = c;
    }
    else
    {
        max = c;
        m = a;
        n = b;
    }
    if (m > n)
    {
        min = n;
        mid = m;
    }
    else
    {
        min = m;
        mid = n;
    }
    return (max * 100 + mid * 10 + min);
}
