#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    printf("age:%i,enter ", n);
    switch (n)
    {
        case 2:
        case 3:
            printf("Lower class\n");
            break;
        case 4:
            printf("Middle class\n");
            break;
        case 5:
        case 6:
            printf("Higher class\n");
            break;
    }
}
