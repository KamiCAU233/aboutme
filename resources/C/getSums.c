#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int sumODD = 0;
    int sumEVEN = 0;
    int ODD = 1;
    if (n % 2 == 1)
    {
        for (int i = 0; i < n / 2 + 1; i++)
        {
            sumODD = sumODD + ODD;
            sumEVEN = sumEVEN + ODD + 1;
            ODD += 2;
        }
    }
    else
    {
        for (int i = 0; i < n / 2; i++)
        {
            sumODD = sumODD + ODD;
            sumEVEN = sumEVEN + ODD + 1;
            ODD += 2;
        }
    }
    int SUM = sumODD + sumEVEN;
    printf("%i\n%i\n%i\n", sumEVEN, sumODD, SUM);
}
