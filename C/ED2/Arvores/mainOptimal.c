#include "optimal.h"

#include <stdlib.h>
#include <stdio.h>

int main()
{
	int i;
	int len;
	int pivot;

	Info *infos;
	Knot *k = NULL;

	printf("No de elementos:");
	scanf("%d", &len);

	infos = (Info*)malloc(sizeof(Info)*len);

	for(i=0;i<len;i++)
	{
		printf("No %d de %d:\n", i+1, len);

		printf("Id: ");
		scanf("%d", &pivot);
		infos[i].id = pivot;

		printf("Frequencia: ");
		scanf("%d", &pivot);
		infos[i].frequency = pivot;
	}

	construct(&k, infos, len);
	mostrar_arvore(k, 0);

	return 0;
}