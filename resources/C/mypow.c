//StudybarCommentBegin
#include<stdio.h>
int main()
{
	int mypow(int x,int n);
	int x,n;
	scanf("%d%d",&x,&n);
	printf("%d\n",mypow(x,n));
        return 0;
}
//StudybarCommentEnd

int mypow(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    x = x * mypow(x, n - 1);
    return x;
}
