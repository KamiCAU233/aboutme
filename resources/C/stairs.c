#include <stdio.h>

int stair(int total);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%i\n", stair(n));
}

int stair(int total)
{
    if (total == 1)
    {
        return 1;
    }
    else if (total == 2)
    {
        return 2;
    }
    else
    {
        return stair(total - 1) + stair(total - 2);
    }
}

