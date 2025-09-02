#include <stdio.h>

int getFactorial(int a, int b);
int getMultiple(int a, int b);

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d %d\n", getFactorial(a, b), getMultiple(a, b));
}

int getFactorial(int a, int b)
{
    int j = a;
    while (j > 0)
    {
        if (a % j == 0 && b % j == 0)
        {
            return j;
            break;
        }
        j--;
    }
    return 1;
}

int getMultiple(int a , int b)
{
    return a * b / getFactorial(a, b);
}
