#include <stdio.h>

void adjust(int *);
int isAvg(int *);

int main()
{
    int candy[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &candy[i]);
    }
    int round;
    for (round = 1; !isAvg(candy); round++)
    {
        adjust(candy);
    }
    printf("%i\n%i\n", round - 1, candy[0]);
}

void adjust(int *n)
{
    int given[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        if (n[i] % 2 != 0)
        {
            n[i]++;
        }
        given[i] = n[i] / 2;
    }
    for (int j = 0; j < 10; j++)
    {
        n[j] = n[j] - given[j];
        if (j == 9)
        {
            n[0] = n[0] + given[9];
        }
        else
        {
            n[j + 1] = n[j + 1] + given[j];
        }
    }
}

int isAvg(int *n)
{
    for (int i = 0; i < 10; i++)
    {
        if (n[0] != n[i])
        {
            return 0;
        }
    }
    return 1;
}

