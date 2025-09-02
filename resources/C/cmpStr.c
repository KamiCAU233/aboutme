#include <stdio.h>
#include <string.h>

int main()
{
    char s1[100];
    char s2[100];
    char s3[100];
    scanf("%s\n%s\n%s", s1, s2, s3);
    char max[100];
    if (strcmp(s1, s2) > 0)
    {
        strcpy(max, s1);
    }
    else
    {
        strcpy(max, s2);
    }
    if (strcmp(max, s3) < 0)
    {
        strcpy(max, s3);
    }
    printf("%s\n", max);
}
