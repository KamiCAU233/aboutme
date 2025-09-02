#include <stdio.h>

int main()
{
    char str1[40];  // double-sized for later appension
    char str2[20];
    scanf("%s", str1);
    scanf("%s", str2);
    int j = 0;
    int k = 0;
    while (str1[j] != 0)
    {
        j++; // j is strlen1 - 1
    }
    while (str2[k] != 0)
    {
        k++; // k is strlen2 - 1
    }
    for (int i = 0; i < k; i++)
    {
        str1[j + i] = str2[i];
    }
    str1[j + k] = 0;
    printf("%s\n", str1);
}
