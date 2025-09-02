#include <stdio.h>

int main()
{
    int a, b;
    int *p1 = &a;
    int *p2 = &b;
    scanf("%d%d", p1, p2);
    if (*p1 < *p2)
    {
        int *temp = p1;
        p1 = p2;
        p2 = temp;
    }
    printf("%d %d\n", *p1, *p2);
}
