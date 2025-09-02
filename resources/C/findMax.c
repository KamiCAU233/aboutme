//StudybarCommentBegin
#include<stdio.h>
int main()
{
	int max(int x[]);
	int x[8],i;
	for(i=0;i<=7;i++)  scanf("%d",&x[i]);
	printf("%d\n",max(x));
	return 0;
}
//StudybarCommentEnd

int max(int x[])
{
    int max = -1e9;
    for (int i = 0; i < 8; i++)
    {
        if (x[i] > max)
        {
            max = x[i];
        }
    }
    return max;
}
