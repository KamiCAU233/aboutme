#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x1, y1, x2, y2, n, m;
	scanf("%d %d", &x1, &y1);
	scanf("%d %d", &x2, &y2);
	scanf("%d%d", &n, &m);
	
	int i = 0;
	int s = 0;
	while (i < 100000)
	{
		int w1 = x1;
		int b1 = y1;
		int w2 = x2;
		int b2 = y2;
		int c = 0;
		while (c < n)
		{
			if ( (rand() % (w1 + b1) + 1) <= w1 )
			{
				w1--;
				//w2++;
			}
			else
			{
				b1--;
				//b2++;
			}
			c++;
		}
		c = 0;
		while (c < n)
		{
			if ( (rand() % (w2 + b2) + 1) <= w2 )
			{
				w2--;
				w1++;
			}
			else
			{
				b2--;
				b1++;
			}
			c++;
		}
		if (w1 == m)
		{
			s++;
		}
		i++;
	}
	printf("%.2f", 1.0 * s / 100000);
}
 
