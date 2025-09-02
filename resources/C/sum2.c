//StudybarCommentBegin
#include <stdio.h>
int main()
{
    int fun(int *p);
	int sum=0, n;
	int *p = &sum;
	n = fun(p);
    printf("%d\n%d\n", n, *p);
	return 0;
}
//StudybarCommentEnd

int fun(int *p)
{
    for (int i = 0; i < 20; i++)
    {
        int n = 2 * i;
        if(*p > 1000)
        {
            *p -= (n - 2) * (n - 2);
            return (n - 4);
        }
        else
        {
            *p += n * n;
        }
    }
    return -1;
}
