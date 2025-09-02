#include <stdio.h>
#include <string.h>

int inStr(char x, char *s);

int main()
{
    char a[100];
    char b[100];
    fgets(a, 100, stdin);
    fgets(b, 100, stdin);
    a[strlen(a) - 1] = 0;
    b[strlen(b) - 1] = 0;
    int count = 0;
    char str[100];
    for (int i = 0; i < strlen(a); i++)
    {
        for (int j = 0; j < strlen(b); j++)
        {
            if (a[i] == b[j])
            {
                if (!inStr(a[i], str))
                {
                    str[count] = a[i];
                    count++;
                }
            }
        }
    }
    str[count] = 0;
    if (count == 0)
    {
        printf("no\n");
    }
    else
    {
        for (int p = 0; p < strlen(str); p++)
        {
            for (int q = 0; q < strlen(str); q++)
            {
                if (str[p] > str[q] && p < q)
                {
                    char tmp = str[p];
                    str[p] = str[q];
                    str[q] = tmp;
                }
            }
        }
        printf("%s\n", str);
    }
}

int inStr(char x, char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (x == s[i])
        {
            return 1;
        }
    }
    return 0;
}
