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
    600, 600, SDL_WINDOW_SHOWN
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

  context->texture_grid = load_texture(context->renderer, "gfx/grid.bmp");
  if(context->texture_grid == NULL) {
    fprintf(stderr, "Falha na inicialização da textura\n");
    return false;
  }

  context->texture_x = load_texture(context->renderer, "gfx/x.bmp");
  if(context->texture_x == NULL) {
    fprintf(stderr, "Falha na inicialização da textura\n");
    return false;
  }

  context->texture_o = load_texture(context->renderer, "gfx/o.bmp");
  if(context->texture_x == NULL) {
    fprintf(stderr, "Falha na inicialização da textura\n");
    return false;
  }

  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

  return context->running = true;
}

void event_handler(struct context *context, SDL_Event *event) {
  handle_event(context, event);
}

void loop(struct context *context) {

}

void render(struct context *context) {
  SDL_RenderClear(context->renderer);
  draw_texture(context->texture_grid, context->renderer, 0 , 0);
  for(int i=0; i<9; i++) {
    int x = (i % 3)*200;
    int y = (i / 3)*200;

    if(context->grid[i] == GRID_TYPE_X) {
      draw_texture(context->texture_x, context->renderer, x, y);
    } else if(context->grid[i] == GRID_TYPE_O) {
      draw_texture(context->texture_o, context->renderer, x, y);
    }
  }
  SDL_RenderPresent(context->renderer);
}

void clean_up(struct context *context) {
  SDL_DestroyTexture(context->texture_grid);
  SDL_DestroyTexture(context->texture_o);
  SDL_DestroyTexture(context->texture_x);
  SDL_DestroyRenderer(context->renderer);
  SDL_DestroyWindow(context->window);

  SDL_Quit();
}