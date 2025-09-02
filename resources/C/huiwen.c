#include <stdio.h>
#include <math.h>

int getLength(int n);
void getReverse(int n);
int getNth(int n, int ordinal); // Get the ORDINALth (from right to left) number of N;

int main()
{
    int n;
    scanf("%d", &n);
    getReverse(n);
    printf("\n");
}


void getReverse(int n)
{
    int ln = getLength(n);
    int num = 0;
    for (int i = 0; i < ln; i++)
    {
        printf("%i", getNth(n, i + 1));
    }
}

int getLength(int n)
{
    int count = 1;
    while (n / 10 != 0)
    {
        count++;
        n = n / 10;
    }
    return count;
}

int getNth(int n, int ordinal)
{
    for (int i = 0; i < ordinal - 1; i++)
    {
        n = n / 10;
    }
    return (n % 10);
}

/*
e.g. getNth(123456, 4)
    Loop times = 4 - 1 = 3;
    Loop 1: n = 12345;
    Loop 2: n = 1234;
    Loop 3: n = 123;

    return (123 % 10) = 3
*/
