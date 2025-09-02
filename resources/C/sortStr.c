//StudybarCommentBegin
#include <stdio.h>
#include <string.h>
int main()
{
    void sort(char p[][20], int n);
    int i, n;
    char p[10][20];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%s", p[i]);
    sort(p, n);
    for (i = 0; i < n; i++)
        printf("%s\n", p[i]);
}
//StudybarCommentEnd

void sort(char p[][20], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (strcmp(p[i], p[j]) > 0 && i > j)
            {
                char str[30];
                strcpy(str, p[i]);
                strcpy(p[i], p[j]);
                strcpy(p[j], str);
            }
        }
    }
}
