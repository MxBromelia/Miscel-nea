#include "table.h"

#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#define MS_VICTORY 1
#define MS_DEFEAT -1
#define MS_UNFINISHED 0

// Insere valores padrões na estrutura de dados
void setup(struct table*, int , int);

// Gera um novo jogo de campo mines_around
void new_game(struct table*, int, int, int);

// Cava um buraco, i.e faz uma jogada
int dig(struct table*, int, int);

// Checa se o jogo continua ou acabou, e no caso do segundo, se o jogador ganhou ou perdeu
int game_status(struct table*);

#endif