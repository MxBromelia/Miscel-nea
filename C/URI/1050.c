#include <stdio.h>

typedef char* string;

typedef struct
{
	int ddd;
	string cidade;
}
codigo;

int main()
{
	codigo codigos[] = {{11, "Sao Paulo"}, {19, "Campinas"}, {21, "Rio de Janeiro"}, {27, "Vitoria"}, {31, "Belo Horizonte"}, {32, "Juiz de Fora"}, {61, "Brasilia"}, {71, "Salvador"}};

	int ddd;

	int begin = 0;
	int end = 7;
	int pivo;

	int found = 0;

	scanf("%d", &ddd);

	while(end - begin > 0)
	{
		pivo = (begin+end)/2;

		if(ddd == codigos[pivo].ddd)
		{
			found = 1;
			break;
		}
		else
			if(ddd > codigos[pivo].ddd)
				begin = pivo;
			else
				end = pivo;
	}

	if(found == 1)
		printf("%s\n", codigos[pivo].cidade);
	else
		printf("DDD nao cadastrado\n");

	return 0;
}