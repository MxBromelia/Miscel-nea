#include <stdio.h>

int main()
{
	const float percentual[] = {0.15, 0.12, 0.1, 0.07, 0.04};

	float salario;
	float reajuste;

	float percento;

	scanf("%f", &salario);

	percento = percentual[(int)((salario-0.1)/400) % 5];
	reajuste = salario*percento;

	printf("Novo salario: %.2f\n", salario+reajuste);
	printf("Reajuste ganho: %.2f\n", reajuste);
	printf("Em percentual: %.2f%%\n", percento*100);

	return 0;
}