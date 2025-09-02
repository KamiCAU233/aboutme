//StudybarCommentBegin
#include <stdio.h>
#include <string.h>

int q_articles(char s[], int* p_a, int* p_an, int* p_the);

int main(int argc, char *argv[])
{
	char x[1024];
	int n, n_a, n_an, n_the;
	fgets(x, 1024, stdin);
    n = q_articles(x, &n_a, &n_an, &n_the);
	printf("%d %d %d %d\n", n, n_a, n_an, n_the);
	return 0;
}
//StudybarCommentEnd

int q_articles(char s[], int* p_a, int* p_an, int* p_the)
{
    char str_a[] = " a ";
    char str_an[] = " an ";
    char str_the[] = " the ";
    *p_a = 0;
    *p_an = 0;
    *p_the = 0;
    while (strstr(s, str_the) != NULL)
    {
        (*p_the)++;
        *strstr(s, str_the) = 'q';
    }
    while (strstr(s, str_an) != NULL)
    {
        (*p_an)++;
        *strstr(s, str_an) = 'q';
    }
    while (strstr(s, str_a) != NULL)
    {
        (*p_a)++;
        *strstr(s, str_a) = 'z';
    }
    str_a[1] = 'A';
    str_an[1] = 'A';
    str_the[1] = 'T';
    while (strstr(s, str_the) != NULL)
    {
        (*p_the)++;
        *strstr(s, str_the) = 'q';
    }
    while (strstr(s, str_an) != NULL)
    {
        (*p_an)++;
        *strstr(s, str_an) = 'q';
    }
    while (strstr(s, str_a) != NULL)
    {
        (*p_a)++;
        *strstr(s, str_a) = 'z';
    }

    strcpy(str_a, "A ");
    strcpy(str_an, "An ");
    strcpy(str_the, "The ");

    while (strstr(s, str_the) != NULL)
    {
        (*p_the)++;
        *strstr(s, str_the) = 'q';
    }
    while (strstr(s, str_an) != NULL)
    {
        (*p_an)++;
        *strstr(s, str_an) = 'q';
    }
    while (strstr(s, str_a) != NULL)
    {
        (*p_a)++;
        *strstr(s, str_a) = 'z';
    }
    return (*p_a + *p_an + *p_the);
}
