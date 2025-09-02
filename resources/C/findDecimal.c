//StudybarCommentBegin
#include<stdio.h>

#define SIZE 20

int main()
{
    int digital_char(char *p);
	char string[SIZE];
    int n;
	fgets(string, SIZE, stdin);
    n = digital_char(string);
    printf("%d\n", n);
	return 0;
}
//StudybarCommentEnd

int digital_char(char *p)
{
    int i = 0;
    int count = 0;
    while (p[i] != '\0')
    {
        if (p[i] >= '0' && p[i] <= '9')
        {
            count++;
        }
        i++;
    }
    return count;
}
