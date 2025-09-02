#include <stdio.h>

void Sort(int x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j && x[i] > x[j])
            {
                int temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }
}



//StudybarCommentBegin
int main()
{
	int a[7],i;
    for(i=0;i<7;i++)  scanf("%d",&a[i]);
    Sort(a,7);
    for(i=0;i<7;i++)  printf("%d ",a[i]);
    return 0;
}
//StudybarCommentEnd
