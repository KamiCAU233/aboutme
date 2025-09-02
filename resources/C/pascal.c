//StudybarCommentBegin
#include <stdio.h>

int main()
{
	void pascals_triangle(int n);
	int n;
	scanf("%d", &n);
	pascals_triangle(n);
	return 0;
}
//StudybarCommentEnd

int pas(int a, int b)
{
    if (b > a)
    {
        return 0;
    }
    else if (b == 1)
    {
        return 1;
    }
    else
    {
        return (pas(a - 1, b - 1) + pas(a - 1, b));
    }
    return -1;
}

void pascals_triangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%5d", pas(i, j));
        }
        printf("\n");
    }
}
