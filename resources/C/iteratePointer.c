#include <stdio.h>

int main()
{
    int x[10];
    int *ptr = &x[0];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", ptr + i);
    }
    for (int j = 0; j < 10; j++)
    {
        printf("%d", *(ptr + j));
        if (j != 9)
        {
            printf(" ");
        }
    }
    printf("\n");
}
