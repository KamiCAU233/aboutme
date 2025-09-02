/*StudybarCommentBegin

#include<stdio.h>
int main()
{
	int f(int x);
	int n;
	scanf("%d",&n);
	printf("%d\n",f(n));
	return 0;
}

StudybarCommentEnd*/

int f(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    return f(n - 1) + f(n - 2);
}
