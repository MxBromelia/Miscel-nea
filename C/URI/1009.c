#include <stdio.h>

int main()
{
	char nome[30];
	double salario;
	double vendas;

	scanf("%s", nome);
	scanf("%lf", &salario);
	scanf("%lf", &vendas);

	printf("TOTAL = R$ %.2lf\n", salario+0.15*vendas);

	return 0;
}