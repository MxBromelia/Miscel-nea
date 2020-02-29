#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdbool.h>
#include<stdio.h>
#include "minesweeper.h"

int mines_around(struct table *table, int pos) {
    int cells_around[] = {
        cell_up(*table, pos), cell_down(*table, pos),
        cell_left(*table, pos), cell_right(*table, pos),
        cell_upper_left(*table, pos), cell_upper_right(*table, pos),
        cell_lower_left(*table, pos), cell_lower_right(*table, pos)
    };

    int mines = 0;
    for(int i=0; i < 8; i++) {
        int check = cells_around[i];
        if(i==-1) continue;
        if(table->field[check] == MINE) mines++;
    }
    return mines;
}

// Põe minas no campo, garantindo que não há minas próximas a posição do primeiro turno do jogador
void place_mines(struct table *table, int frow, int fcol) {
    int fcell = cell(*table, frow, fcol);

    for(int i = 0; i < table->num_mines; i++) {
        int candidate = rand() % cells(*table);

        if(candidate == fcell) {
            table->field[candidate] = 0;
            i--;
            continue;
        }
        table->field[candidate] = '*';
        if(mines_around(table, fcell) > 0) {
            table->field[candidate] = 0;
            i--;
            continue;
        }
    }
}

void setup(struct table *table, int rows, int cols) {
    int num_cells = rows*cols;
    table->rows = rows;
    table->cols = cols;
    table->status = MS_UNFINISHED;
    table->last_turn = -1;
    table->last_checked_turn = -1;
    table->cells_digged = 0;
    memcpy(table->digged, (bool[]) {[0 ... 1024] = false}, num_cells);
}

void new_game(struct table *table, int mines, int x, int y) {
    srand((unsigned)time(NULL));
    int num_cells = cells(*table);

    table->num_mines = mines;
    place_mines(table, x, y);

    for(int i=0; i< num_cells; i++) {
        if(table->field[i] != '*')
            table->field[i] = '0' + mines_around(table, i);
    }
}

void propagate(struct table *table, int pos) {
    if(pos == -1) return;
    if(table->digged[pos]) return;

    table->digged[pos] = true;
    table->cells_digged++;

    if(table->field[pos] == '0') {
        propagate(table, cell_up(*table, pos));
        propagate(table, cell_down(*table, pos));
        propagate(table, cell_left(*table, pos));
        propagate(table, cell_right(*table, pos));
    }
}

int dig(struct table *table, int row, int col) {
    int cell = table->cols*row + col;

    table->last_turn = cell;
    propagate(table, cell);

    return game_status(table);
}


int game_status(struct table *table) {
    int victory_turn = cells(*table) - table->num_mines;

    if(table->last_checked_turn == table->last_turn)        return table->status;
    table->last_checked_turn = table->last_turn;

    if(table->field[table->last_turn] == '*')
        return table->status = MS_DEFEAT;

    if(table->cells_digged >= victory_turn)
        return table->status = MS_VICTORY;

    return table->status = MS_UNFINISHED;
}