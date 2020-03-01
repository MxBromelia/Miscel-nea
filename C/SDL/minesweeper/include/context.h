#ifndef CONTEXT_H
#define CONTEXT_H

#include <SDL2/SDL.h>
#include <stdbool.h>

#include "table.h"
#include "minesweeper.h"

struct context {
  bool running;

  SDL_Window *window;
  SDL_Renderer *renderer;

  SDL_Texture *texture;

  struct table game;
};

extern const struct context default_context;

#endif