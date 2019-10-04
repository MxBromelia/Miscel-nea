#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PROB 0
#define VALUE 1

#define MAX_ENTRY 20
#define NUM_COLS 9

#define MAX(x,y) x > y ? x : y

enum column { number, interval, clocktime, service, start, queue, end, total, idle};

int data_entry[3][2] = {{ 35, 10},
                      { 75, 12},
                      {100, 14}};
int data_service[3][2] = {{ 30, 9},
                        { 80,10},
                        {100,11}};

/*
	Simulação de uma fila do banco
	---------------------------------------------
	Tabela de Simulação
	1. Número do Cliente, MAX=20
	2. Tempo desde a última entrada (min)
		10: 35%, 12: 40%, 14: 25%
	3. Tempo de chegada no relógio (min)
	4. Tempo de serviço (min)
		9: 30%, 10: 50%, 11: 20%
	5. Tempo do início de serviço (min)
	6. Tempo na fila (min)
	7. Tempo final do serviço (min)
	8. Tempo de fila + serviço (min)
	9. Tempo livre do caixa
*/

int get_value(int input, int data[][2])
{
	int i = 0;

	while(input > data[i][PROB]) i++;

	return data[i][VALUE];
}

//Gera uma coluna que usa os valores e as probabilidades(acumuladas) em data
void generate_column(int num_entry, int data[][2], int *ret)
{
	int i;

	for(i=0;i<num_entry;i++)
		ret[i] = get_value(rand() % 100,data);
}

//Gera a tabela coluna por coluna
void simulate(int num_entry, int table[][NUM_COLS])
{
	int column[num_entry];
	int i,j;
	
	
	for(i=0;i<num_entry;i++)
		for(j=0;j<9;j++)
			table[i][j] = 0;
	//Coluna 1: Incremental
	for(i=0;i<num_entry;i++)
		table[i][0] = i+1;
	
	//Coluna 2: Geração aleatória
	generate_column(num_entry, data_entry, column);
	for(i=0;i<num_entry;i++)
		table[i][1] = column[i];
	
	//Coluna 3: Acúmulo de tempos da coluna 1
	table[0][2] = table[0][1];
	for(i=1;i<num_entry;i++)
		table[i][2] = table[i-1][2] + table[i][1];
	
	//Coluna 4: Geração aleatória
	generate_column(num_entry, data_service, column);
	for(i=0;i<num_entry;i++)
		table[i][3] = column[i];
	
	//Coluna 5: tempo que o cliente chega ou o serviço anterior é encerrado, o maior
	table[0][4] = table[0][1];
	for(i=1;i<num_entry;i++)
		table[i][4] = MAX(table[i-1][3]+table[i-1][4],table[i][2]);
	
	//Coluna 6: inicio do serviço - tempo de chegada
	for(i=0;i<num_entry;i++)
		table[i][5] = table[i][4]-table[i][2];
	
	//Coluna 7: inicio do serviço + tempo de execução
	for(i=0; i<num_entry;i++)
		table[i][6] = table[i][3]+table[i][4];
	
	//Coluna 8: momento de saida - momento de entrada
	for(i=0; i<num_entry;i++)
		table[i][7] = table[i][6]-table[i][2];
	
	//Coluna 9: início da execução - fim da execução anterior
	table[0][8] = table[0][1];
	for(i=1; i<num_entry; i++)
		table[i][8] = table[i][4]-table[i-1][6];
}

int main()
{
	int table[MAX_ENTRY][NUM_COLS];
	int i,j;

	srand((unsigned)time(NULL));
	simulate(MAX_ENTRY,table);

	printf("Table:\tnum\tentrada\trelogio\tservico\tinicio\tfila\tfinal\ttotal\tlivre\n");
	for(i=0;i<MAX_ENTRY;i++)
	{
		printf("row %02d:", i);
		for(j=0;j<NUM_COLS;j++)
			printf(" %03d\t", table[i][j]);
		printf("\n");
	}

    return 0;
}

