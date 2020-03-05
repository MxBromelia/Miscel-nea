#include "event_handler.h"

void handle_quit(struct context *context) {
  context->running = false;
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
    break;
  case SDL_MOUSEBUTTONUP:
    break;
  }
}