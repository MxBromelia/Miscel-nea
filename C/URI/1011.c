#include <stdio.h>

#define PI 3.14159

int main()
{
	int raio;

	scanf("%d", &raio);

	printf("VOLUME = %.3lf\n", (double) 4/3*PI*raio*raio*raio);

	return 0;
}