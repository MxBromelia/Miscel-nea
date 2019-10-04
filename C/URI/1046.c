#include <stdio.h>

int main()
{
	int ini, fim;
	int horas;

	scanf("%d %d", &ini, &fim);

	horas = fim - ini;
	if(horas<=0)
		horas = horas + 24;
	printf("O JOGO DUROU %d HORA(S)\n", horas);

	return 0;
}