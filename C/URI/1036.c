#include <math.h>
#include <stdio.h>

int main()
{
	double a, b, c;

	double rDelta;

	scanf("%lf %lf %lf", &a, &b, &c);

	rDelta = pow(b,2) - 4*a*c;

	if(rDelta>0 && a!= 0)
	{
		rDelta = sqrt(rDelta);

		printf("R1 = %.5lf\n", (-b + rDelta)/(2*a));
		printf("R2 = %.5lf\n", (-b - rDelta)/(2*a));
	}
	else
		printf("Impossivel calcular\n");

	return 0;
}