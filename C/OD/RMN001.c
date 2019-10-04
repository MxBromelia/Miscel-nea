//Avaliação de Ordenação de Dados UECE 2016.1
//Este programa foi elaborado por Ruan Macambira do Nascimento
#include <stdio.h>
#include <string.h>

#define NUM_ALUNOS 9
#define NUM_NOTAS 10

#define POS_LEN 101

int main()
{
	int i;
	int j;

	float notas[NUM_ALUNOS][NUM_NOTAS+1];
	char nome[NUM_ALUNOS][20];

	int position;
	int pos[POS_LEN];
	float notasOrd[NUM_ALUNOS][NUM_NOTAS+1];
	char nomeOrd[NUM_ALUNOS][20];

	FILE* dados;

	if((dados = fopen("dados.txt", "r")) != NULL)
	{
		for(i=0;i<NUM_ALUNOS;i++)
		{
			fscanf(dados, "%s", nome[i]);

			for(j=0, notas[i][NUM_NOTAS] = 0;j<NUM_NOTAS;j++)
			{
				fscanf(dados, "%f", &notas[i][j]);

				notas[i][NUM_NOTAS] = notas[i][NUM_NOTAS] + notas[i][j]/NUM_NOTAS;
			}
		}

		printf("Matriz Desordenada:\n");
		for(i=0;i<NUM_ALUNOS;i++)
		{
			printf("%8s\t", nome[i]);

			for(j=0;j<NUM_NOTAS;j++)
			{
				printf("%2.1f ", notas[i][j]);
			}
			printf("%2.2f", notas[i][NUM_NOTAS]);

			printf("\n");
		}
		printf("\n");

		//Counting Sort
		for(i=0;i<POS_LEN;i++)
			pos[i] = 0;

		for(i=0;i<NUM_ALUNOS;i++)
			pos[(int)(notas[i][NUM_NOTAS]*10)]++;

		for(i=1;i<POS_LEN;i++)
			pos[i] += pos[i-1];

		for(i=0;i<NUM_ALUNOS;i++)
		{
			position = (int)(notas[i][NUM_NOTAS]*10);
			pos[position]--;

			strcpy(nomeOrd[pos[position]],nome[i]);
			for(j=NUM_NOTAS;j>=0;j--)
				notasOrd[pos[position]][j] = notas[i][j];
			notasOrd[pos[position]][NUM_NOTAS] = notas[i][NUM_NOTAS];
			
		}

		for(i=0;i<NUM_ALUNOS;i++)
		{
			strcpy(nome[i], nomeOrd[i]);

			for(j=0;j<NUM_NOTAS+1;j++)
				notas[i][j] = notasOrd[i][j];
		}

		printf("Matriz Ordenada:\n");
		for(i=0;i<NUM_ALUNOS;i++)
		{
			printf("%8s\t", nome[i]);

			for(j=0;j<NUM_NOTAS;j++)
			{
				printf("%2.1f ", notas[i][j]);
			}
			printf("%2.2f", notas[i][NUM_NOTAS]);

			printf("\n");
		}
		printf("\n");

		printf("Aprovados e Reprovados:\n");
		for(i=0;i<NUM_ALUNOS;i++)
		{
			printf("%8s: ", nome[i]);
			printf("Media %2.2f", notas[i][NUM_NOTAS]);
			printf(" - %s", ((notas[i][NUM_NOTAS] >= 7) ? ("Passou") : ("Reprovou")));

			printf("\n");
		}

	}
	else
		printf("Erro na leitura do arquivo!");

	return 0;
}