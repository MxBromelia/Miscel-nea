#include <stdio.h>
#include <math.h>

typedef struct
{
	int r;
	int x;
	int y;
} Circulo;

int main()
{
	Circulo a, b;

	double dist;

	while(scanf("%d %d %d %d %d %d", &a.r, &a.x, &a.y, &b.r, &b.x, &b.y) != EOF)
	{
		dist = sqrt((double)pow(a.x - b.x, 2) + pow(a.y - b.y, 2));

		if(dist > (double) a.r - b.r)
			printf("MORTO\n");
		else
			printf("RICO\n");
	}
	return 0;
}