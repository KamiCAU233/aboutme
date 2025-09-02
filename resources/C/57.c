#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if (n % 7 == 0 && n % 5 == 0)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
}
