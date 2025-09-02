#include <stdio.h>
#include <string.h>

void insertion(char *str1, char *str2, int index);

int main()
{
    char str1[100];
    char str2[100] = "ab";
    scanf("%s", str1);
    // Find the max character in str1:
    int max = str1[0];
    int max_index = 0;
    for (int i = 0; i < strlen(str1); i++)
    {
        if (str1[i] >= max)
        {
            max = str1[i];
            max_index = i;  // Get max character and its index;
        }
    }
    insertion(str1, str2, max_index);
    printf("%s\n", str1);
}

void insertion(char *str1, char *str2, int index)
{
    int ln1 = strlen(str1);
    int ln2 = strlen(str2);
    for (int i = 0; i < ln1 - index; i++)
    {
        str1[ln1 + ln2 - i] = str1[ln1 - i];
    }
    for (int j = 0; j < ln2; j++)
    {
        str1[index + j + 1] = str2[j];
    }
}
