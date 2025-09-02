#include <stdio.h>
#include <math.h>

int isPrime(int n);

int main()
{
    int x[10];
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &x[i]);
    }
    for (int ii = 0; ii < 10; ii++)
    {
        if (!isPrime(x[ii]))
        {
            x[count] = x[ii];
            count++;
        }
    }
    for (int iii = 0; iii < count; iii++)
    {
        for (int j = 0; j < count; j++)
        {
            if (x[iii] > x[j] && iii < j)
            {
                int temp = x[iii];
                x[iii] = x[j];
                x[j] = temp;
            }
        }
    }
    if (count == 0)
    {
        printf("No\n");
    }
    else
    {
        for (int p = 0; p < count; p++)
        {
            printf("%d ", x[p]);
        }
        printf("\n");
    }


}

int isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

