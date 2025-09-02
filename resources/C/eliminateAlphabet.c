//StudybarCommentBegin
#include <stdio.h>
#include <string.h>
int main()
{
        void GetLetters(char *s);
        char str[100];
        gets(str);
        GetLetters(str);
        printf("%s",str);
        return 0;
}
//StudybarCommentEnd

void GetLetters(char *s)
{
    char tmp[100];
    int count = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            continue;
        }
        else
        {
            tmp[count] = s[i];
            count++;
        }
    }
    strcpy(s, tmp);
    s[count] = '\0';
}
