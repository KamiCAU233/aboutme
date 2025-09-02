#include <stdio.h>

int getLength(int n);
int getNth(int n, int ordinal);
int getCube(int n);
int isArmstrong(int n);

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        if (isArmstrong(i))
        {
            if (i != 1) printf(" ");
            printf("%d", i);
        }
    }
    printf("\n");
}

int getLength(int n)
{
    int length = 1;
    for (int i = n; i / 10 != 0; i = i / 10)
    {
        length++;
    }
    return length;
}

int getNth(int n, int ordinal)
{
    for (int i = 1; i < ordinal; i++)
    {
        n = n / 10;
    }
    return n % 10;
}

int getCube(int n)
{
    return n * n * n;
}

int isArmstrong(int n)
{
    int sum = 0;
    for (int i = 0; i < getLength(n); i++)
    {
        sum = sum + getCube(getNth(n, i + 1));
    }
    return (sum == n);
}
