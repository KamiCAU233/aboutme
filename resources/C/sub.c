#include <stdio.h>
#include <string.h>

int subCount(char *s, char *t);

int main()
{
    char str1[100];
    char str2[100];
    fgets(str1, 100, stdin);
    fgets(str2, 100, stdin);
    printf("%d\n", subCount(str1, str2));
}

int subCount(char *s, char *t)
{
    int count = 0;
    while (strstr(s, t) != NULL)
    {
        *strstr(s, t) = 'q';
        count++;
    }
    return count;
}
