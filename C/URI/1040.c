#include <stdio.h>

int main()
{
	int i;
	int pesos[] = {2,3,4,1};

	double notas[4];
	double media = 0;
	double exame;

	for(i=0;i<4;i++)
	{
		scanf("%lf", &notas[i]);

		media += notas[i]*pesos[i]/10;
	}

	printf("Media: %.1lf\n", media);

	if(media >= 7)
		printf("Aluno aprovado.\n");
	else
		if(media >= 5)
		{
			printf("Aluno em exame.\n");

			scanf("%lf", &exame);
			printf("Nota do exame: %.1lf\n", exame);

			media = (exame + media)/2;
			if( media >= 5)
				printf("Aluno aprovado.\n");
			else
				printf("Aluno reprovado.\n");

			printf("Media final: %.1lf\n", media);
		}
		else
			printf("Aluno reprovado.\n");

	return 0;
}