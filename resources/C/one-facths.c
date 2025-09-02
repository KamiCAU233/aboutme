//StudybarCommentBegin
#include<stdio.h>
int main()
{
	double mul(int n);
	int n;
	scanf("%d",&n);
	printf("%.2f\n",mul(n));
	return 0;
}
//StudybarCommentEnd

double mul(int n)
{
    int fac(int n);
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return mul(n - 1) + 1.0 / fac(n);
    }
}

int fac(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return fac(n - 1) * n;
    }
}
