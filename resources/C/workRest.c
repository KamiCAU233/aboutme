#include <stdio.h>

int isLeap(int);
int getGap(int, int, int);

int main()
{
    int yy, mm, dd;
    scanf("%d%d%d", &yy, &mm, &dd);
    int gap = getGap(yy, mm, dd);
    if (gap % 7 < 5)
    {
        printf("working\n");
    }
    else
    {
        printf("resting\n");
    }
}

int isLeap(int n)
{
    if (n % 400 == 0 || (n % 100 != 0 && n % 4 == 0))
    {
        return 1;
    }
    return 0;
}

int getGap(int yy, int mm, int dd)
{
    int gap = 0;
    // From Jan 1, 1981
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeap(yy))
    {
        days[1] = 29;
    }
    for (int y = 1981; y < yy; y++)
    {
        if (isLeap(y))
        {
            gap += 366;
        }
        else
        {
            gap += 355;
        }
    }
    for (int m = 1; m < mm; m++)
    {
        gap += days[m - 1];
    }
    gap += dd;
    return gap - 1;
}
