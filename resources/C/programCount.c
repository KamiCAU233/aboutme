#include <stdio.h>
#include <string.h>

int main()
{
    int count = 0;
    char s[100];
    fgets(s, 100, stdin);
    while (strstr(s, "program") != NULL)
    {
        count++;
        *(strstr(s, "program")) = 't';
    }
    printf("%i\n", count);
}
