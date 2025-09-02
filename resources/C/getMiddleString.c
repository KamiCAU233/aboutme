#include <stdio.h>

int getLength(char *string);
char* getMiddle(char *string);

int main()
{
    char string[100];
    scanf("%s", string);
    printf("%s\n", getMiddle(string));
}

int getLength(char *string)
{
    int i = 0;
    while (string[i] != '\0')
    {
        i++;
    }
    return i;
}

char* getMiddle(char *string)
{
    int ln = getLength(string);
    if (ln % 2 != 0)
    {
        int middle = (ln + 1) / 2;     // Not zero-based index;
        string[middle] = '\0';
        return (string + middle - 1);
    }
    else
    {
        int middle = ln / 2;
        string[middle + 1] = '\0';
        return (string + middle - 1);
    }
}
