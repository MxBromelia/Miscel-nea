#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* f;

	char letra[3];
	char l;

	f = fopen("texto", "r");

	if(f == NULL)
	{
		printf("Erro\n");

		return 0;
	}

	while(fscanf(f, "%s", letra) != EOF)
	{
		l = atoi(letra);

		printf("%c", l);
	}
	printf("\n");

	return 0;
}