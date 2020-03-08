#include "event_handler.h"

void handle_quit(struct context *context) {
  context->running = false;
}

void handle_left_button_down(struct context *context, int x, int y) {
  int id = (x / 200) + (y / 200) * 3;

  if(context->grid[id] != GRID_TYPE_NONE) return;

  if(context->current_player == 0) {
    set_game_cell(context, id, GRID_TYPE_O);
    context->current_player = 1;
  } else {
    set_game_cell(context, id, GRID_TYPE_X);
    context->current_player = 0;
  }
}

void handle_event(struct context *context, SDL_Event *event) {
  switch(event->type) {
  case SDL_QUIT:
    handle_quit(context);
    break;
  case SDL_WINDOWEVENT:
    break;
  case SDL_TEXTINPUT:
    break;
  case SDL_KEYDOWN:
    break;
  case SDL_KEYUP:
    break;
  case SDL_MOUSEMOTION:
    break;
  case SDL_MOUSEBUTTONDOWN:
    switch(event->button.button) {
    case SDL_BUTTON_LEFT:
      handle_left_button_down(context, event->button.x, event->button.y);
    }
    break;
  case SDL_MOUSEBUTTONUP:
    break;
  }
}