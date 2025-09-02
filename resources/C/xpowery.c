#include <stdio.h>

int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
    int result = 1;
    for (int i = 0; i < y;  i++)
    {
        result = result * x;
        if (result > 1000)
        {
            result = result % 1000;
        }
    }
    printf("%d\n", result);
}
