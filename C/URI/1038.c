#include <stdio.h>

typedef struct
{
	int id;
	double valor;
} Produto;

const double menu[] = {4, 4.5, 5, 2, 1.5};

int main()
{
	int id;
	int qtd;

	scanf("%d %d", &id, &qtd);

	printf("Total: R$ %.2lf\n", menu[id-1]*qtd);

	return 0;
}