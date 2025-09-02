#include <stdio.h>
#include <string.h>
#include <ctype.h>

char conversion(char x);

int main()
{
    char a[100];
    scanf("%s", a);
    for (int i = 0; i < strlen(a); i++)
    {
        if (isalpha(a[i]))
        {
            a[i] = conversion(a[i]);
        }
    }
    printf("%s\n", a);
}

char conversion(char x)
{
    if (x == 'S') return '7';
    if (x == 'V') return '8';
    if (x == 'Y' || x == 'Z') return '9';
    int num = (int)(x - 'A') / 3 + 2;
    return (num + '0');
}
