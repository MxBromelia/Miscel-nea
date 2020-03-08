#ifndef CONTEXT_H
#define CONTEXT_H

#include <SDL2/SDL.h>
#include <stdbool.h>

enum {
  GRID_TYPE_NONE,
  GRID_TYPE_X,
  GRID_TYPE_O
};

struct context {
  bool running;
  int current_player;
  int grid[9];

  SDL_Window *window;
  SDL_Renderer *renderer;

  SDL_Texture *texture_grid;

  SDL_Texture *texture_o;
  SDL_Texture *texture_x;
};

extern const struct context default_context;

void game_reset(struct context*);

void set_game_cell(struct context*, int, int);

#endif