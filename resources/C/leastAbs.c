#include <stdio.h>
int abs(int n)
{
    if (n < 0)
    {
        return -n;
    }
    return n;
}
int main()
{
    int num[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &num[i]);
    }
    int min = abs(num[0]);
    int min_index = 0;
    for (int j = 0; j < 10; j++)
    {
        if (abs(num[j]) < min)
        {
            min = abs(num[j]);
            min_index = j;
        }
    }
    printf("%d", num[min_index]);
}
