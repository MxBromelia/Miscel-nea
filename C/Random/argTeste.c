#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *v, int len);

int main(int argc, char* argv[])
{
	int *vector;
	int len;
	int max;

	int i;

	srand((unsigned)time(NULL));

	if(argc == 3)
	{
		len = atoi(argv[1]);
		max = atoi(argv[2]);

		vector = (int*) malloc(sizeof(int)*len);

		printf("v:");
		for(i=0;i<len;i++)
		{
			vector[i] = rand() % max;

			printf("\t%d", vector[i]);
		}
		printf("\n");

		insertionSort(vector, len);

		printf("v(ord):");
		for(i=0;i<len;i++)
			printf("\t%d", vector[i]);
		printf("\n");
	}
	else
		printf("Entrada invalida\n");

	return 0;
}

void insertionSort(int *v, int len)
{
	int i;
	int j;
	int pivo;

	for(i=1;i<len;i++)
	{
		for(j=i-1, pivo = v[i]; j>=0; j--)
		{
			v[j+1] = v[j];

			if(pivo > v[j])
				break;
		}

		v[j+1] = pivo;
	}
}