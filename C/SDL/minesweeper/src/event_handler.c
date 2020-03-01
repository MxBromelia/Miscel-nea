#include "event_handler.h"
#include "minesweeper.h"

void handle_quit(struct context *context) {
  context->running = false;
}

void handle_mouse_left_button_down(struct context *context, int x, int y) {  
  int col = x / 32;
  int row = y / 32;

  if(context->game_started == false) {
    context->game_started = true;
    new_game(&(context->game), 10, col, row);
  }

  dig(&(*context).game, row, col);
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
      handle_mouse_left_button_down(context, event->button.x, event->button.y);
      break;
    case SDL_BUTTON_MIDDLE:
      break;
    case SDL_BUTTON_RIGHT:
      break;
    }
    break;
  case SDL_MOUSEBUTTONUP:
    break;
  }
}