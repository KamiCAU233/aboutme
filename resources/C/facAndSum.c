//StudybarCommentBegin
#include<stdio.h>
int main()
{
    int sum(int n);
	int n;
	scanf("%d",&n);
	printf("%d\n",sum(n));
	return 0;
}
//StudybarCommentEnd
int fac(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * fac(n - 1);
    }
}
int sum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return sum(n - 1) + fac(n);
    }
}
