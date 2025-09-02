#include <stdio.h>
#include <string.h>

void word_count(char *s)
{
    int ln = strlen(s);
    int count = 0;
    for (int i = 0; i < ln; i++)
    {
        if (s[i] != ' ')
        {
            count++;
        }
        else
        {
            if (count != 0) printf("%d ", count);
            count = 0;
        }
        if (s[i] == '\n' || s[i] == 0 || s[i] == '.')
        {
            printf("%d ", count - 1);
            count = 0;
        }
    }
    printf("\n");
}

//StudybarCommentBegin
int main()
{
    char msg[100];
    fgets(msg, 100, stdin);
    word_count(msg);
}
//StudybarCommentEnd
