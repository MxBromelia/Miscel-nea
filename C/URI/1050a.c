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
	int i;

	scanf("%d", &ddd);

	for(i=0;i<8;i++)
		if(ddd == codigos[i].ddd)
			break;

	if(i < 8)
		printf("%s\n", codigos[i].cidade);
	else
		printf("DDD nao cadastrado\n");

	return 0;
}