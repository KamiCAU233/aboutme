#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50], str2[30];
    char ch;
    int index = 0;
    scanf("%s\n", str1);
    scanf("%c", &ch);
    int count = 0;
    for (int i = 0; i < strlen(str1); i++)
    {
        if (str1[i] != ch)
        {
            str2[index] = str1[i];
            index++;
        }
    }
    str2[index] = 0;
    printf("%s\n", str2);
}
