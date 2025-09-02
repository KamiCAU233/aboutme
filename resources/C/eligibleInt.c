#include <stdio.h>

int main()
{
    int a;
    int x = 0;
    scanf("%d", &a);
    while (x <= a)
    {
        if(x * x % 391 == 13)
        {
            printf("%i ", x);
        }
        x++;
    }
    printf("\n");
}
