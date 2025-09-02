#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);
	double delta = b * b - 4 * a * c;
	double xi = (-b + sqrt(delta)) / 2 / a;
	double xii = (-b - sqrt(delta)) / 2 / a;
	printf("%.2f %.2f", xi, xii);
}
