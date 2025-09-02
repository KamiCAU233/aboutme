#include <stdio.h>

int main()
{
    int sum = 0;
    for (int i = 1; i <= 20; i++)
    {
        sum = sum + (2 * i - 1) * (2 * i - 1);
    }
    printf("%i\n", sum);
}
