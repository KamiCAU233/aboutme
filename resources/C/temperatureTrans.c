//StudybarCommentBegin
#include <stdio.h>
int main()
{
	double Trans(double x);
	double x;
	scanf("%lf", &x);
	printf("%.2f\n", Trans(x));
	return 0;
}
//StudybarCommentEnd

double Trans(double x)
{
    double f = x * 9 / 5 + 32;
    return f;
}
