#include <stdio.h>

int isLeap(int year);

int main()
{
    int yy, mm, dd;
    scanf("%d,%d,%d", &yy, &mm, &dd);
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int count = 0;
    if (isLeap(yy) == 0)
    {
        days[1] = 29;
    }
    if (dd > days[mm - 1] || mm > 12)
    {
        printf("data error.\n");
        return 1;
    }
    for (int i = 0; i < mm - 1; i++)
    {
        count = count + days[i];
    }

    count = count + dd;
    printf("It is the %dth day.\n", count);
}

int isLeap(int year)
{
    if (year % 100 == 0)
    {
        if (year % 400 == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else if (year % 4 == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
