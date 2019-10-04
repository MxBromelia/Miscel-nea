#include <stdio.h>

typedef struct
{
	int codigo;
	int qtde;
	float preco;
} unidade;

int main()
{
	unidade u[2];

	scanf("%d %d %f", &u[0].codigo, &u[0].qtde, &u[0].preco);
	scanf("%d %d %f", &u[1].codigo, &u[1].qtde, &u[1].preco);

	printf("VALOR A PAGAR: R$ %.2f\n", u[0].qtde*u[0].preco + u[1].qtde*u[1].preco);

	return 0;
}