//StudybarCommentBegin
#include <stdio.h>

int isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
//StudybarCommentEnd

int getWhatDay(int y)
{
    int gap = 0;
    for (int i = 2023; i < y; i++)
    {
        if (isLeapYear(i + 1))
        {
            gap += 366;
        }
        else
        {
            gap += 365;
        }
    }
    return (2 + gap % 7) % 7;
}

void printSchedule(int n)
{
    if (getWhatDay(n) != 0 && getWhatDay(n) != 6)
    {
        printf("%i1226, unavailable\n", n);
        return;
    }
    else if ((n - 2024) % 2 == 1 || (n - 2024) % 5 == 0)
    {
        if (getWhatDay(n) == 6)
        {
            printf("%i1226, Chairman Mao commemoration, 27th, flag-raising ceremony, location Beijing\n", n);
        }
        else if (getWhatDay(n) == 0)
        {
            printf("%i1225, flag-raising ceremony, 26th, Chairman Mao commemoration, location Beijing\n", n);
        }
    }
    else
    {
        printf("%i1226, Chairman Mao commemoration, location Shaoshan Hunan\n", n);
    }
}

//StudybarCommentBegin
int main()
{
    int year;
    scanf("%d", &year);
    printSchedule(year);
    return 0;
}
//StudybarCommentEnd
