#include <stdio.h>

double resto(double num, double div)
{
	while(num>=div)
		num = num-div;

	return num;
}

int main()
{
	double valor;

	scanf("%lf", &valor);

	printf("NOTAS:\n");

	printf("%d nota(s) de R$ 100,00\n", (int)valor/100);
	valor = resto(valor, 100);

	printf("%d nota(s) de R$ 50,00\n", (int)valor/50);
	valor = resto(valor, 50);

	printf("%d nota(s) de R$ 20,00\n", (int)valor/20);
	valor = resto(valor, 20);

	printf("%d nota(s) de R$ 10,00\n", (int)valor/10);
	valor = resto(valor, 10);

	printf("%d nota(s) de R$ 5,00\n", (int)valor/5);
	valor = resto(valor, 5);

	printf("%d nota(s) de R$ 2,00\n", (int)valor/2);
	valor = resto(valor, 2);

	printf("MOEDAS:\n");

	printf("%d moeda(s) de R$ 1,00\n", (int)valor);
	valor = resto(valor, 1);

	printf("%d moeda(s) de R$ 0,50\n", (int)(valor/0.5));
	valor = resto(valor, 0.5);

	printf("%d moeda(s) de R$ 0,25\n", (int)(valor/0.25));
	valor = resto(valor, 0.25);

	printf("%d moeda(s) de R$ 0,10\n", (int)(valor/0.1));
	valor = resto(valor, 0.1);

	printf("%d moeda(s) de R$ 0,05\n", (int)(valor/0.05));
	valor = resto(valor, 0.05);

	printf("%d moeda(s) de R$ 0,01\n", (int)(valor/0.01));

	return 0;
}