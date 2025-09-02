//StudybarCommentBegin
#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	void jdgprime(int n);
	scanf("%d", &n);
	jdgprime(n);
	return 0;
}
//StudybarCommentEnd

void jdgprime(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			printf("%d*%d\n", i, n / i);
			return;
		}
	}
	printf("y\n");
}
