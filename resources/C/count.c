#include <stdio.h>
#include <string.h>

int letterCount(char *s);
int numberCount(char *s);
int spaceCount(char *s);
int otherCount(char *s);

int main()
{
    char str[100];
    fgets(str, 100, stdin);
    printf("letter=%d,number=%d,space=%d,other=%d\n", letterCount(str), numberCount(str), spaceCount(str), otherCount(str));
}

int letterCount(char *s)
{
    int ln = strlen(s);
    int count = 0;
    for (int i = 0; i < ln; i++)
    {
        if ((*(s + i) >= 'a' && *(s + i) <= 'z') || (*(s + i) >= 'A' && *(s + i) <= 'Z'))
        {
            count++;
        }
    }
    return count;
}
int numberCount(char *s)
{
    int ln = strlen(s);
    int count = 0;
    for (int i = 0; i < ln; i++)
    {
        if (*(s + i) >= '0' && *(s + i) <= '9')
        {
            count++;
        }
    }
    return count;
}
int spaceCount(char *s)
{
    int ln = strlen(s);
    int count = 0;
    for (int i = 0; i < ln; i++)
    {
        if (*(s + i) == ' ')
        {
            count++;
        }
    }
    return count;
}
int otherCount(char *s)
{
    int ln = strlen(s);
    int count = ln - letterCount(s) - spaceCount(s) - numberCount(s);
    return count;
}
