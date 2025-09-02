#include <stdio.h>
// Remember to intialize i, j, k right before each while loop.
// Or when the inner loop ends the value of k will stay 5 and doesn't iterate.
// The same thing doesn't happen in for loop where you initialize the value of the counter just in
// its bracket.

int main()
{
    int n;
    scanf("%d", &n);
    int counter = 0;
    int total = 0;
    int i = 1;
    while (i <= 5)
    {
        int j = 1;
        while (j <= 5)
        {
            int k = 1;
            while (k <= 5)
            {
                if (i + j + k == n)
                {
                    counter++;
                    // printf("%i + %i + %i = %i\n", k, j, i, n);
                }
                // printf("%i %i %i TOTAL\n", i, j, k);
                total++;
                k++;
            }
            j++;
        }
        i++;
    }
    // printf("%i / %i = %.2f\n", counter, total, 1.0 * counter / total);
    printf("%.2f\n", 1.0 * counter / total);
}
