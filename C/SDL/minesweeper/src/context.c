#include "context.h"

const struct context default_context = {
  .running = false,
  .game_started = false,
  .window = NULL,
  .renderer = NULL,
};

void free_context(struct context *context) {
  free_tileset(&(*context).field_states);
  free_tileset(&(*context).cell_states);

  SDL_DestroyRenderer(context->renderer);
  SDL_DestroyWindow(context->window);
}