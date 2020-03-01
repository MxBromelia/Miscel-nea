#include <stdio.h>
#include "window.h"
#include "display_element.h"
#include "event_handler.h"

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
    fprintf(stderr, "Falha durante a inicialização do SDL\n");
    return false;
  }

  context->window = SDL_CreateWindow(
    "Campo Minado",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    640, 480, SDL_WINDOW_SHOWN
  );
  if(context->window == NULL) {
    fprintf(stderr, "Falha durante a criação da janela\n");
    return false;
  }

  context->renderer = SDL_CreateRenderer(context->window, -1, 0);
  if(context->renderer == NULL) {
    fprintf(stderr, "Falha durante a inicialização do renderer\n");
    return false;
  }
  SDL_SetRenderDrawColor(context->renderer, 0, 0, 0, 255);
  SDL_RenderClear(context->renderer);
  SDL_RenderPresent(context->renderer);

  context->texture = load(context->renderer, "thumbs_up.bmp");
  if(context->texture == NULL) {
    fprintf(stderr, "Falha na inicialização da textura\n");
    return false;
  }

  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

  return context->running = true;
}

void event_handler(struct context *context, SDL_Event *event) {
  // if(event->type == SDL_QUIT) {
  //   context->running = false;
  // }
  handle_event(context, event);
}

void loop(struct context *context) {

}

void render(struct context *context) {
  SDL_RenderClear(context->renderer);
  draw_texture(context->texture, context->renderer, 0, 0);
  draw_partial_texture(context->texture, context->renderer, 100, 100, &((SDL_Rect) {.w = 32, .h = 32}));

  SDL_RenderPresent(context->renderer);
}

void clean_up(struct context *context) {
  SDL_DestroyTexture(context->texture);
  SDL_DestroyRenderer(context->renderer);
  SDL_DestroyWindow(context->window);

  SDL_Quit();
}