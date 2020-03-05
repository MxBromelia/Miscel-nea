#include "context.h"

const struct context default_context = {
  .running = false,
  .current_player = 0,
  .grid = {[0 ... 8] = GRID_TYPE_NONE},
  .window = NULL,
  .renderer = NULL,
  .texture_grid = NULL,
  .texture_o = NULL,
  .texture_x = NULL,
};

void game_reset(struct context *context) {
  for(int i=0; i<9; i++) {
    context->grid[i] = GRID_TYPE_NONE;
  }
}

void set_game_cell(struct context *context, int id, int type) {
  if(id < 0 || id > 9) return;
  if(type < 0 || type > GRID_TYPE_O) return;

  context->grid[id] = type;
}