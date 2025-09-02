#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if (n == 1 || n == 2 || n == 3)
    {
        printf("1\n");
    }
    else
    {
        int c = 3;
        int first = 1;
        int second = 1;
        int third = 1;
        int sum = 0;
        while (c < n)
        {
            sum = first + second + third;
            first = second;
            second = third;
            third = sum;
            c++;
        }
        printf("%i\n", sum);
    }
}
