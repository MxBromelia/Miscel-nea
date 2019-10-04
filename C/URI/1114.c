#include <stdio.h>

#define SENHA 2002

int main()
{
	int senha;

	while(scanf("%d", &senha), senha != SENHA)
		printf("Senha Invalida\n");
	printf("Acesso Permitido\n");

	return 0;
}