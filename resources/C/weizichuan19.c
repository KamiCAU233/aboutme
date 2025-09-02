#include <stdio.h>
#include <math.h>

int f(int n)
{
	int i, m, a;
	if (n < 10)
	{
		for (i = 1; i <= 9; i++)
		{
			m = i * 10 + n;
			a = sqrt(m);
			if (a * a == m)
			{
				return 0;
			} // m 是完全平方数

		}
		return 1;
	}
	else if (n < 100)
	{
		for (i = 1; i <= 9; i++)
		{
			m = i * 100 + n;
			a = sqrt(m);
			if (a * a == m)
			{
				return 0;
			}

		}
		return 1;
	}
}

int main()
{
	int i, a;
	for (i = 1; i <= 99; i++)
	{
		if (f(i) == 0) printf("%d ", i);
	}
	return 0;
}
