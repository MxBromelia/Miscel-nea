#ifndef TABLE_H
#define TABLE_H

#include <stdbool.h>

#define NO_POSITION -1
#define NOTHING 2
#define MINE '*'
#define DIGGED 3

struct table {
    int rows; // Número de Linhas na campo
    int cols; // Número de Colunas na campo
    char field[1024]; // Campo
    bool digged[1024]; // Campo(Excavado)
    bool flagged[1024]; //Campo(Marcado)

    int num_mines; //Número de minas no campo
    int mines[1024]; //Posição de todas as minas no campo

    int cells_digged; //Número da jogada
    int last_checked_turn; // última jogada em que houve uma checagem de vitória
    int last_turn; //Última jogada

    int status; // Status do jogo (Vitória, Derrota, Jogo não acabou)
};

int cell(struct table, int, int);

int cells(struct table);

int cell_up(struct table, int);

int cell_down(struct table, int);

int cell_left(struct table, int);

int cell_right(struct table, int);

int cell_upper_left(struct table, int);

int cell_upper_right(struct table, int);

int cell_lower_left(struct table, int);

int cell_lower_right(struct table, int);

#endif