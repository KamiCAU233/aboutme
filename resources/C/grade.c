#include <stdio.h>

int main()
{
    int grade;
    scanf("%d", &grade);
    if (grade >= 90)
    {
        printf("%i belongs to A.", grade);
    }
    else if (grade > 60)
    {
        printf("%i belongs to B.", grade);
    }
    else if (grade > 0 && grade <= 59)
    {
        printf("%i belongs to C.", grade);
    }
}
