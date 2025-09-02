#include <stdio.h>

int main()
{
    int apple = 2;
    int sum = 0;
    int day = 0;
    while (apple < 100)
    {
        sum = sum + apple;
        apple = apple * 2;
        day++;
    }
    double average = sum * 0.8 / day;
    printf("%.2lf\n", average);
}
