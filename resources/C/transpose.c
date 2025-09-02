//StudybarCommentBegin
#include <stdio.h>
//StudybarCommentEnd

void transposition(int a[20][20], int n, int m)
{
    printf("array A:\n");
    for (int r = 0; r < n; r++)
    {
        for (int q = 0; q < m; q++)
        {
            printf("%5d", a[r][q]);
        }
        printf("\n");
    }
    printf("array B:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%5d", a[j][i]);
        }
        printf("\n");
    }
}

//StudybarCommentBegin
int main()
{
	int i, j, n, m, a[20][20];
	scanf("%d%d", &n, &m);
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)  scanf("%d", &a[i][j]);
	transposition(a, n, m);
}
//StudybarCommentEnd
