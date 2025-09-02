#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    unsigned int total = 1000000;
    unsigned int boysFirst = total / 2;
    unsigned int girlsFirst = total / 2;
    unsigned int girlsSecondBefore = girlsFirst / 2;
    unsigned int girlsSecondAfter = girlsSecondBefore * (1 - 0.01 * n);
    unsigned int boysSecondBefore = girlsFirst / 2;
    unsigned int boysSecondAfter = boysSecondBefore * (1 + 0.01 * n);
    unsigned int boys = boysFirst + boysSecondAfter;
    unsigned int girls = girlsFirst + girlsSecondAfter;
    //printf("%d %d\n", boys, girls);
    printf("%.2lf\n", (1.0 * boys) / (1.0 * girls));
}
