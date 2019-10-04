#include <stdio.h>

#define RATO 0
#define SAPO 1
#define COELHO 2

int main()
{
	int num;
	char type;

	int total = 0;
	int qtd[3] = {0, 0, 0};

	int casos;

	scanf("%d", &casos);

	while(casos > 0)
	{
		scanf("%d %c", &num, &type);

		total = total + num;

		switch(type)
		{
			case 'R':
				qtd[RATO] = qtd[RATO] + num;
				break;
			case 'S':
				qtd[SAPO] = qtd[SAPO] + num;
				break;
			case 'C':
				qtd[COELHO] = qtd[COELHO] + num;
				break;
		}

		casos--;
	}

	printf("Total: %d cobaias\n", total);
	printf("Total de coelhos: %d\n", qtd[COELHO]);
	printf("Total de ratos: %d\n", qtd[RATO]);
	printf("Total de sapos: %d\n", qtd[SAPO]);
	printf("Percentual de coelhos: %.2f %%\n", (float)100*qtd[COELHO]/total);
	printf("Percentual de ratos: %.2f %%\n", (float)100*qtd[RATO]/total);
	printf("Percentual de sapos: %.2f %%\n", (float)100*qtd[SAPO]/total);

	return 0;
}