#include <stdio.h>

int main()
{
	int num;
	scanf("%d", &num);
	int n = num;
	int t = 1;
	int j = 0;
	int sum = 0;
	while (n / 10 != 0)
	{
		n = n / 10;
		t = t + 1;
	}
	while (num != 0)
	{
		j = num % 10;
		sum = sum + j;
		num = num / 10;
	}
	printf("count=%d\nsum=%d", t, sum);
}
