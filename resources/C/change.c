//StudybarCommentBegin
#include<stdio.h>
int main()
{
	void chg(int *a, int *b);
	int x, y, *a, *b;
	a = &x;
	b = &y;
	scanf("%d%d", a, b);
	if(x < y) chg(a, b);
	printf("%d %d\n", x, y);
	return 0;
}
//StudybarCommentEnd

void chg(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
