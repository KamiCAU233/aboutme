#include <stdio.h>

int gap(int yy, int mm, int dd);
int isLeap(int yy);

int main()
{
    int yy, mm, dd;
    scanf("%d%d%d", &yy, &mm, &dd);
    if (gap(yy, mm, dd) % 5 < 4)
    {
        printf("He was sleeping at that day.");
    }
    else
    {
        printf("He was fishing at that day.");
    }
}

int gap(int yy, int mm, int dd)
{
    int day = 0;
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 1990; i < yy; i++)
    {
        if (isLeap(i))
        {
            day += 366;
        }
        else
        {
            day += 365;
        }
    }
    for (int j = 0; j < mm - 1; j++)
    {
        day += days[j];
    }
    day += dd;
    return day;
}

int isLeap(int yy)
{
    if ((yy % 4 == 0 && yy % 100 != 0) || yy % 400 == 0)
    {
        return 1;
    }
    return 0;
}
