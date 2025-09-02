#include <stdio.h>

int main()
{
    char str[100];
    char vowels[11] = "aeiouAEIOU";
    scanf("%s", str);
    int i = 0;
    while (str[i] != 0)
    {
        for (int j = 0; j < 10; j++)
        {
            if (str[i] == vowels[j])
            {
                printf("%c", vowels[j]);
            }
        }
        i++;
    }
    printf("\n");
}
