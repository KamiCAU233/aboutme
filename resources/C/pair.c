#include <stdio.h>

int getLength(int n);
int getNth(int n, int ordinal);
int isPair(int n);

int main()
{
    int pairs[2000];
    int index = 0;
    for (int i = 12; i < 10000; i++)
    {
        if (isPair(i))
        {
            pairs[index] = i;
            index++;
        }
    }
    int n;
    scanf("%d", &n);
    for (int p = 0; p < n; p++)
    {
        printf("%i %i\n", pairs[p], pairs[p] + 1);
    }
}

int getLength(int n)
{
    int ln = 1;
    while (n / 10 != 0)
    {
        n = n / 10;
        ln++;
    }
    return ln;
}

int getNth(int n, int ordinal) // 1-based
{
    for (int i = 0; i < ordinal - 1; i++)
    {
        n = n / 10;
    }
    return (n % 10);
}

int isPair(int n)
{
    int ln1 = getLength(n);
    int sum1 = 0;
    for (int i = 1; i <= ln1; i++)
    {
        sum1 = sum1 + getNth(n, i);
    }
    int ln2 = getLength(n + 1);
    int sum2 = 0;
    for (int ii = 1; ii <= ln2; ii++)
    {
        sum2 = sum2 + getNth(n + 1, ii);
    }
    if (sum1 % 8 == 0 && sum2 % 8 == 0)
    {
        return 1;
    }
    return 0;
}
