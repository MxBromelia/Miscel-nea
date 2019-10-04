#include <stdio.h>

int main()
{
	float media;
	float nota;

	int valido;
	int continua = 1;

	while(continua != 2)
	{
		media = 0;
		valido = 2;

		while(valido > 0)
		{
			scanf("%f", &nota);

			if(nota >= 0 && nota <= 10)
			{
				valido--;
				media = media + nota;
			}
			else
				printf("nota invalida\n");
		}

		media = media / 2;
		printf("media = %.2f\n", media);

		do
		{
			printf("novo calculo (1-sim, 2-nao)\n");
			scanf("%d", &continua);
		}
		while(continua != 1 && continua != 2);

	}
	

	return 0;
}