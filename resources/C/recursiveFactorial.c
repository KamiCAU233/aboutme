//StudybarCommentBegin
#include <stdio.h>
int main()
{
    int p(int n);
    int n;
    scanf("%d", &n);
    printf("%d", p(n));
}
//StudybarCommentEnd

int p(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * p(n - 1);
    }
    return -1;
}
