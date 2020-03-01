#ifndef CONTEXT_H
#define CONTEXT_H

#include <SDL2/SDL.h>
#include <stdbool.h>

#include "table.h"
#include "minesweeper.h"
#include "tileset.h"

struct context {
  bool running;
  bool game_started;

  SDL_Window *window;
  SDL_Renderer *renderer;

  SDL_Texture *texture;

  struct table game;

  struct tileset field_states;

  struct tileset cell_states;
};

void free_context(struct context *);

extern const struct context default_context;

#endif