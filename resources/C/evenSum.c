#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 100; i <= n; i = i + 2)
    {
        sum = sum + i;
    }
    printf("%d\n", sum);
}
