//StudybarCommentBegin
#include <stdio.h>
int main()
{
	void in_num(int *x);
	void exchange(int *x);
	void out_num(int *x);
	int x[10];
	in_num(x);
	exchange(x);
	out_num(x);
	return 0;
}
//StudybarCommentEnd

void in_num(int *x)
{
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", x + i);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void exchange(int *p)
{
    int max = *p;
    int max_index = 0;
    int min = *p;
    int min_index = 0;
    for (int i = 0; i < 10; i++)
    {
        int num = *(p + i);
        if (num > max)
        {
            max = num;
            max_index = i;
        }
        if (num < min)
        {
            min = num;
            min_index = i;
        }
    }
    swap(p, p + min_index);
    swap(p + 9, p + max_index);
}


void out_num(int *x)
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d", *(x + i));
        if (i != 9)
        {
            printf(" ");
        }
    }
    printf("\n");
}
