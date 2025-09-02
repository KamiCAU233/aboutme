//StudybarCommentBegin
#include <stdio.h>
#include <stdlib.h>

int main()
{
    void fun(int *p, int a);
    int num, i, a[5];
    scanf("%d", &num);
    fun(a, num);
    for (i = 4; i >= 0; i--)
        printf("%d", a[i]);
    printf("\n");
    return 0;
}
//StudybarCommentEnd

void fun(int *p, int a)
{
    char str[6];
    sprintf(str, "%d", a);
    for (int i = 0; i < 5; i++)
    {
        str[i] = str[i] + 5;
        if (str[i] > '9')
        {
            str[i] = str[i] - 10;
        }
    }
    int temp = str[0];
    str[0] = str[4];
    str[4] = temp;

    temp = str[1];
    str[1] = str[3];
    str[3] = temp;

    for (int j = 4; j > -1; j--)
    {
        *(p + j) = str[4 - j] - '0';
    }
}
