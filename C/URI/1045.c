#include <stdio.h>

#define A p[0]
#define B p[1]
#define C p[2]

int main()
{
	double p[3];
	double pivo;
	int i, j;

	scanf("%lf %lf %lf", &p[0], &p[1], &p[2]);

	for(i=1;i<3;i++)
	{
		pivo = p[i];

		for(j = i-1; j>=0 && p[j] < pivo; j--)
			p[j+1] = p[j];
		p[j+1] = pivo;
	}

	if(p[0]>=p[1]+p[2])
		printf("NAO FORMA TRIANGULO\n");
	else
		if(p[0]*p[0] > p[1]*p[1] + p[2]*p[2])
			printf("TRIANGULO OBTUSANGULO\n");
		else
			if(p[0]*p[1] < B*B + C*C)
				printf("TRIANGULO ACUTANGULO\n");
			else
				printf("TRIANGULO RETANGULO\n");

	if(B == C)
	{
		if(A == B)
			printf("TRIANGULO EQUILATERO\n");
		else
			printf("TRIANGULO ISOCELES\n");
	}
	else
		if(A == B)
			printf("TRIANGULO ISCOCELES\n");

	return 0;
}