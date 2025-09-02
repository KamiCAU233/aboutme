//StudybarCommentBegin
#include<stdio.h>
int main()
{
	void order(int x[]);
	int x[10], i;
	for (i=0;i<=9;i++)
	{
		scanf("%d",&x[i]);
	}
	order(x);
	for (i=0;i<=9;i++)
	{
		printf("%d ",x[i]);
	}
}
//StudybarCommentEnd


void order(int x[])
{
	for (int i = 0; i < 10; i++)
	{
		int minIndex;
		int min = 1e9;
		for (int j = i; j < 10; j++)
		{
			if (x[j] < min)
			{
				min = x[j];
				minIndex = j;
			}
		}
		int temp = min;
		x[minIndex] = x[i];
		x[i] = temp;
	}
}


int main()
