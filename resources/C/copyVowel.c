#include <stdio.h>

int main()
{
    char string[100];
    char copy[100];
    scanf("%s", string);
    int counter = 0;
    for(int i = 0; i < 100; i++)
    {
        char g = string[i];
        char gg = g - 'A' + 'a';
        if ((g == 'a' || g == 'e' || g == 'i' || g == 'o' || g == 'u'|| gg == 'a' || gg == 'e' || gg == 'i' || gg == 'o' || gg == 'u') && g != 0)
        {
            copy[counter] = g;
            counter++;
        }
    }
    for (int j = 0; j < counter; j++)
    {
        for (int k = 0; k < counter; k++)
        {
            if (copy[k] > copy[k + 1] && copy[k + 1] != 0)
            {
                char tmp = copy[k];
                copy[k] = copy[k + 1];
                copy[k + 1] = tmp;
            }
        }
    }
    printf("%s\n", copy);
}
