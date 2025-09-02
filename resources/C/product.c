//StudybarCommentBegin
#include<stdio.h>

int main()
{
	int product(int a[], int n);
	int a[6]={1, 2, 3, 4, 5, 6};
    printf("%d\n", product(a, 6));
	return 0;
}

//StudybarCommentEnd

int product(int a[], int n)
{
    if (n == 1)
    {
        return a[0];
    }
    else
    {
        return product(a, n - 1) * a[n - 1];
    }
    return -1;
}
