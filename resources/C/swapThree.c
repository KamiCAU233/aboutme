//StudybarCommentBegin
#include <stdio.h>
int main()
{
	void exchange(int *a, int *b, int *c);
	int x, y, z;
	int *a = &x, *b = &y, *c = &z;
	scanf("%d%d%d", a, b, c);
	exchange(a, b, c);
	printf("%d %d %d\n",x, y, z);
	return 0;
}
//StudybarCommentEnd

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void exchange(int *a, int *b, int *c)
{
    if (*a < *b)
    {
        swap(a, b);
    }
    if (*b < *c)
    {
        swap(b, c);
    }
    if (*a < *b)
    {
        swap(a, b);
    }
}
