#include <stdio.h>

int main()
{
    int a[50];
    int i = 0;
    do
    {
        scanf("%d", &a[i]);
        i++;
    } while (a[i - 1] != -1);

    int count[5] = {0};

    for (int j = 0; j < i; j++)
    {
        if (a[j] < 5 && a[j] > -1)
        {
            count[a[j]]++;
        }
    }
    for (int k = 0; k < 5; k++)
    {
        printf("%i:%i\n", k, count[k]);
    }
}
