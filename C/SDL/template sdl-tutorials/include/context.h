#ifndef CONTEXT_H
#define CONTEXT_H

#include <SDL2/SDL.h>
#include <stdbool.h>

struct context {
  bool running;

  SDL_Window *window;
  SDL_Renderer *renderer;

  SDL_Texture *texture;
};

extern const struct context default_context;

#endif