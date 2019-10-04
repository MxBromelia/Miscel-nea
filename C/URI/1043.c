#include <stdio.h>

int main()
{
	double l[3];

	scanf("%lf %lf %lf", &l[0], &l[1], &l[2]);

	if(l[0] + l[1] > l[2] && l[0] + l[0] + l[2] > l[1] && l[1] + l[2] > l[0])
		printf("Perimetro = %.1lf\n", l[0]+l[1]+l[2]);
	else
		printf("Area = %.1lf\n", (l[0] + l[1])*l[2]/2);

	return 0;
}