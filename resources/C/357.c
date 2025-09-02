#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int count = 0;
    printf("%d:", n);
    int d[3] = {3, 5, 7};
    for (int i = 0; i < 3; i++)
    {
        if (n % d[i] == 0)
        {
            if (count != 0)
            {
                printf(",");
            }
            printf("%d", d[i]);
            count++;
        }
    }
    if (count == 0)
    {
        printf("no");
    }
    printf("\n");
}
