//StudybarCommentBegin
#include <stdio.h>
int main()
{
	int prime(int n);
	int num, a;
	do
	{
		scanf("%d", &num);
	} while (num <= 6 || num % 2 == 1);
	for (a = 2; a <= num / 2 + 1; a++)
		if (prime(a) && prime(num-a))
			printf("%d=%d+%d\n", num, a, num - a);
	return 0;
}
//StudybarCommentEnd

int prime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
