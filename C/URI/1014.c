#include <stdio.h>

int main()
{
	double km, litros;

	scanf("%lf", &km);
	scanf("%lf", &litros);

	printf("%.3lf km/l\n", km/litros);

	return 0;
}