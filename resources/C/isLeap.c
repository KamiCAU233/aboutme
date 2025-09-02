#include <stdio.h>

int main()
{
    int year;
    scanf("%d", &year);
    if (year % 100 == 0)
    {
        if (year % 400 == 0)
        {
            printf("y\n");
        }
        else
        {
            printf("n\n");
        }
    }
    else if (year % 4 == 0)
    {
        printf("y\n");
    }
    else
    {
        printf("n\n");
    }
}
