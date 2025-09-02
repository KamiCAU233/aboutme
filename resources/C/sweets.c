#include <stdio.h>

int getSweets(int num, int days);

int main()
{
    int sweets = getSweets(1, 10);
    printf("%d\n", sweets);
}

int getSweets(int num, int days)
{
    if (days == 1)
    {
        return num;
    }
    else
    {
        return getSweets((num + 1) * 2, days - 1);
    }
}
