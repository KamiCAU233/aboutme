#include <stdio.h>

int main()
{
	int num;
	scanf("%d", &num);
	int a = num / 100;
	int b = (num - a * 100) / 10;
	int c = num - a * 100 - b * 10;
	int new = 100 * c + 10 * b + a;
	printf("%i", new);
}
