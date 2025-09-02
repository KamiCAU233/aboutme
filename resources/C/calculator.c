#include <stdio.h>

int main()
{
    float a, c;
    char b;
    scanf("%f%c%f", &a, &b, &c);
    if (b == '+')
    {
        printf("%.2f", a + c);
    }
    if (b == '-')
    {
        printf("%.2f", a - c);
    }
    if (b == '*')
    {
        printf("%.2f", a * c);
    }
    if (b == '/')
    {
        if(c == 0)
        {
            printf("error");
        }
        else
        {
            printf("%.2f", a / c);
        }
    }
    printf("\n");
}
