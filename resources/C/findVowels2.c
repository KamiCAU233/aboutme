#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    scanf("%s", str);
    int count = 0;
    char vowel[] = "aeiouAEIOU";
    for (int i = 0; i < strlen(str); i++)
    {
        for (int j = 0; j < strlen(vowel); j++)
        {
            if (str[i] == vowel[j])
            {
                count++;
            }
        }
    }
    printf("%d\n", count);
}
