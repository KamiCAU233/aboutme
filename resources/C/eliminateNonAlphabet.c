//StudybarCommentBegin
#include <stdio.h>
#include <string.h>

int main()
{
        void GetLetters(char *s);
        char str[100];
        fgets(str, 100, stdin);
        GetLetters(str);
        printf("%s\n", str);
}
//StudybarCommentEnd

void GetLetters(char *s)
{
    int x = 0;
    while (s[x] != 0)
    {
        x++;
    }
    int ln = x;
    for (int i = 0; i < ln; i++)
    {
        if ((s[i] < 'a' || s[i] > 'z') && (s[i] < 'A' || s[i] > 'Z'))
        {
            for (int j = i; j < ln; j++)
            {
                s[j] = s[j + 1];
            }
            i--;
            ln--;
        }
    }
}

