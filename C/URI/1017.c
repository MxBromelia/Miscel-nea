#include <stdio.h>

int main()
{
	int kmh, h;

	scanf("%d", &h);
	scanf("%d", &kmh);

	printf("%.3lf\n", (double)kmh*h/12);

	return 0;
}