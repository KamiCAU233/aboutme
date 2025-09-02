#include <stdio.h>

double add(double a, double b);

int main()
{
    double a, b;
    scanf("%lf %lf", &a, &b);
    printf("%.2lf\n", add(a, b));
}

double add(double a, double b)
{
    return a + b;
}
