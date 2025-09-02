#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int index = 0;
    char str[100];
    fgets(str, 100, stdin);
    str[strlen(str)] = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (isupper(str[i]))
        {
            index = str[i] - 'A';
            printf("%c", 'Z' - index);
        }
        else if (islower(str[i]))
        {
            index = str[i] - 'a';
            printf("%c", 'z' - index);
        }
        else
        {
            printf("%c", str[i]);
        }
    }
}
