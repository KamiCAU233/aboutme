#include <stdio.h>

int isPerfect(int n);

int main()
{
   for (int i = 400; i < 501; i++)
   {
        if (isPerfect(i))
        {
            printf("%d\n", i);
        }
   }
}

int isPerfect(int n)
{
    int factors[500];
    int index = 0;
    int sum = 0;
    // Store all of n's factor in an array
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }

    }
    return (sum == n);
}
