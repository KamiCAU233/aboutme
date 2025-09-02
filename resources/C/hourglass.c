#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int counter = 0;

    for (int i = 0; i < n; i++)
    {
        int spaces = i;
        int counts = 2 * (n - i) + 1;
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < counts; k++)
        {
            printf("%i", counter % 9 + 1);
            counter++;
        }
        printf("\n");
    }

    for (int ii = 0; ii < n + 1; ii++)
    {
        int spaces = n - ii;
        int counts = 2 * ii + 1;
        for (int jj = 0; jj < spaces; jj++)
        {
            printf(" ");
        }
        for (int kk = 0; kk < counts; kk++)
        {
            printf("%i", counter % 9 + 1);
            counter++;
        }
        printf("\n");
    }
}
