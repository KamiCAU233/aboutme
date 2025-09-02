//StudybarCommentBegin
#include <stdio.h>
//StudybarCommentEnd

int getMax(int n)
{
    int p[3];
    p[0] = n / 100;
    p[1] = n / 10 - 10 * p[0];
    p[2] = n - 10 * p[1] - 100 * p[0];
    int max = p[0], min = p[1];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i < j && p[i] < p[j])
            {
                int temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    return (100 * p[0] + 10 * p[1] + p[2]);
}

int getMin(int n)
{
    int p[3];
    p[0] = n / 100;
    p[1] = n / 10 - 10 * p[0];
    p[2] = n - 10 * p[1] - 100 * p[0];
    int max = p[0], min = p[1];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i < j && p[i] < p[j])
            {
                int temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    return (p[0] + 10 * p[1] + 100 * p[2]);
}

void blackhole_3(int n)
{
    int dif = getMax(n) - getMin(n);
    if (n == dif)
    {
        printf("%d\n", dif);
    }
    else
    {
        blackhole_3(dif);
    }
}

//StudybarCommentBegin
int main()
{
	int num;
	scanf("%d", &num);
	blackhole_3(num);
	return 0;
}
//StudybarCommentEnd
