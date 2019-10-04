#include <stdio.h>

int main()
{
	float media = 0;
	float nota;

	int valido = 2;

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

	return 0;
}