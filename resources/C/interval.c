//StudybarCommentBegin
#include <stdio.h>
#include <string.h>
int main()
{
	void output(char *q);
	char x[20];
	fgets(x, 10, stdin);
	output(x);
	return 0;
}
//StudybarCommentEnd

void output(char *q)
{
    int ln = strlen(q);
    for (int i = 0; i < ln; i++)
    {
        if (i % 2 == 0)
        {
            printf("%c", q[i]);
        }
    }
    printf("\n");
}
