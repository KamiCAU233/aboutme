#include <stdio.h>

int main()
{
	const double pi = 3.141592657;
	double r, dia, inner_dia;
	scanf("%lf%lf", &dia, &inner_dia);
	r = dia / 200.0;
	double ir = inner_dia / 200.0;
	double volume = (4.0/3.0) * pi * r * r * r;
	double inner_volume = (4.0/3.0) * pi * ir * ir * ir;
	printf("%f\n", (volume - inner_volume) * 11340.0);
}
