#include <stdio.h>

typedef struct
{
	int hora;
	int minuto;
} horario;

int main()
{
	horario inicio, fim;
	horario tempo;

	scanf("%d %d %d %d", &inicio.hora, &inicio.minuto, &fim.hora, &fim.minuto);

	tempo.minuto = fim.minuto - inicio.minuto;
	tempo.hora = fim.hora - inicio.hora;

	if(tempo.minuto < 0)
	{
		tempo.minuto = tempo.minuto + 60;
		tempo.hora--;
	}

	if(tempo.hora < 0 || (tempo.hora == 0 && tempo.minuto == 0))
		tempo.hora = tempo.hora + 24;

	printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", tempo.hora, tempo.minuto);

	return 0;
}