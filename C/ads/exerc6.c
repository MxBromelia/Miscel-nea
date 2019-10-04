#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20

#define PROB 0
#define VALUE 1

#define MAX_ENTRY 20

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

void generate_column(int num_entry, int data[][2], int *ret)
{
    int i;
    int rng;

    for(i=0;i<num_entry;i++)
    {
        rng = rand() % 100;

        ret[i] = get_value(rng,data);
    }
}

void simulate(int num_entry, int table[][9])
{
    int column[num_entry];
    int i,j;

    for(i=0;i<MAX_ENTRY;i++)
        for(j=0;j<9;j++)
            table[i][j] = 0;

    generate_column(num_entry, data_entry, column);
    for(i=0;i<num_entry;i++)
    {
        table[i][1] = column[i];
        //printf("%d ", table[i][1]);
        //printf("%d ", column[i]);
    }

    generate_column(num_entry, data_service, column);
    for(i=0;i<num_entry;i++)
    {
        table[i][3] = column[i];
        //printf("%d ", table[i][3]);
        //printf("%d ", column[i]);
    }
}

int main()
{
    int table[MAX_ENTRY][9];
    int i,j;

    srand((unsigned)time(NULL));
    simulate(MAX_ENTRY,table);

    printf("Table:\n");
    for(i=0;i<MAX_ENTRY;i++);
    {
        printf("row %02d:", i);
        for(j=0;j<9;j++)
            printf(" %02d", table[i][j]);
        printf("\n");
    }

    return 0;
}
