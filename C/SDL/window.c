#include "window.h"

int execute(struct context *context) {
  if(init(context) == false) {
    return EXIT_FAILURE;
  }

  SDL_Event event;

  while(context->running) {
    while(SDL_PollEvent(&event)) {
      event_handler(context, &event);
    }

    loop(context);
    render(context);
  }

  clean_up(context);
  return EXIT_SUCCESS;
}

bool init(struct context *context) {
  if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    return false;
  }

  context->window = SDL_CreateWindow(
    "Campo Minado",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    640, 480, SDL_WINDOW_SHOWN
  );
  if(context->window == NULL) {
    return false;
  }

  context->renderer = SDL_CreateRenderer(context->window, -1, 0);
  if(context->renderer == NULL) {
    return false;
  }

  SDL_SetRenderDrawColor(context->renderer, 0, 0, 0, 255);
  SDL_RenderClear(context->renderer);
  SDL_RenderPresent(context->renderer);

  return context->running = true;
}

void event_handler(struct context *context, SDL_Event *event) {
  if(event->type == SDL_QUIT) {
    context->running = false;
  }
}

void loop(struct context *context) {

}

void render(struct context *context) {

}

void clean_up(struct context *context) {
  SDL_Quit();
}