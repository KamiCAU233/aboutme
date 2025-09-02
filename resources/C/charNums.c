#include <stdio.h>
#include <string.h>

int char_numbers(char *s);

int main()
{
    char str[100];
    fgets(str, 100, stdin);
    str[strlen(str)] = 0;
    printf("There are %d chars in \"%s\"\n", char_numbers(str), str);
}

int char_numbers(char *s)
{
    int count = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if ((*(s + i) >= 'a' && *(s + i) <= 'z') || (*(s + i) >= 'A' && *(s + i) <= 'Z'))
        {
            count++;
        }
    }
    return count;
}
