//StudybarCommentBegin
#include <stdio.h>
int main()
{
	int fun(double *p);
	double sum = 0;
	double *p = &sum;
	int n;
	n = fun(p);
    printf("%d\n%lf\n", n, *p);
	return 0;
}
//StudybarCommentEnd

int fun(double *p)
{
    *p = 0;
    int i;
    for (i = 1; *p < 5; i++)
    {
        *p = *p + 1.0 / i;
    }
    return i - 1;
}
