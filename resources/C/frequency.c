#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    fgets(str, 100, stdin);
    int fre[10] = {0};
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            fre[str[i] - '0']++;
        }
    }
    int max = 0;
    for (int j = 0; j < 10; j++)
    {
        if (fre[j] > max)
        {
            max = fre[j];
        }
    }
    for (int t = 9; t > -1; t--)
    {
        if (fre[t] == max)
        {
            printf("%d\n", t);
            return 0;
        }
    }
}
