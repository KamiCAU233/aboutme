//StudybarCommentBegin
#include <stdio.h>
#include <math.h>

int main()
{
	double sum(int n);
	int n;
	scanf("%d", &n);
	printf("%.3f\n", sum(n));
	return 0;
}
//StudybarCommentEnd

double sum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return sum(n - 1) + pow(-1, n - 1) * 1.0 / n;
    }
}
