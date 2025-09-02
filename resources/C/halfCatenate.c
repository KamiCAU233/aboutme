#include <stdio.h>
#include <string.h>

int main()
{
    char a[100];
    char b[100];
    char c[100];
    scanf("%s%s", a, b);
    int la = strlen(a);
    int lb = strlen(b);
    strncpy(c, a, la / 2);
    c[la / 2] = 0;
    for (int i = 0; i < lb / 2; i++)
    {
        c[la / 2 + i] = b[lb / 2 + i];
    }
    c[la / 2 + lb / 2] = 0;
    for (int m = 0; m < la / 2 + lb / 2; m++)
    {
        for (int n = 0; n < la / 2 + lb / 2; n++)
        {
            if (c[m] > c[n] && m < n)
            {
                char temp = c[n];
                c[n] = c[m];
                c[m] = temp;
            }
        }
    }
    printf("%s\n", c);
}
