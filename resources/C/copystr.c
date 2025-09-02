//StudybarCommentBegin
#include <stdio.h>
#include <string.h>
int main()
{
	int m;
	void copystr(char *, char*, int);
	char str1[80], str2[80];
	fgets(str2, 80, stdin);
	scanf("%d", &m);
	if(strlen(str2) < m)  printf("error!");
	else
	{	copystr(str1, str2, m);
		printf("%s", str1);
	}
	return 0;
}
//StudybarCommentEnd

void copystr(char *str1, char *str2, int n)
{
    for (int i = n - 1; i < strlen(str2) + 1; i++)
    {
        str1[i - (n - 1)] = str2[i];
    }
}
