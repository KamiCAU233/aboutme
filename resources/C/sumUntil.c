#include <stdio.h>

int main()
{
    double sum = 0;
    for (int i = 1; 1.0 / i > 0.0001; i++)
    {
        if (i % 2 == 0)
        {
            sum -= 1.0 / i;
        }
        else
        {
            sum += 1.0 / i;
        }
    }
    printf("%.6lf\n", sum);
}
