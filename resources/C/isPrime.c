#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    int t = 2;
    if (n == 1 || n == 2)
    {
        printf("y\n");
        return 0;
    }
    while (sqrt(n) >= t)
// To cut down runtime, just check if the sqrt of n is greater than t.
// "=" ensures if t is exactly the square root of n, then t * t equals n, which means t is a factor.
    {
        if (n % t == 0)
        {
            printf("n\n");
            return 1;
        }
        t = t + 1;
    }
    printf("y\n");
}
