#include <math.h>
#include <stdio.h>

typedef struct
{
	double x;
	double y;
} coord;

int main()
{
	coord c[2];

	scanf("%lf %lf", &c[0].x, &c[0].y);
	scanf("%lf %lf", &c[1].x, &c[1].y);

	printf("%.4lf\n", sqrt(pow(c[0].x-c[1].x,2) + pow(c[0].y-c[1].y, 2)));

	return 0;
}