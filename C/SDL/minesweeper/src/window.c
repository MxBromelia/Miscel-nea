#include <stdio.h>
#include "window.h"
#include "display_element.h"
#include "event_handler.h"
#include "minesweeper.h"

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

  setup(&(*context).game, 8, 8);

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
  SDL_SetRenderDrawBlendMode(context->renderer, SDL_BLENDMODE_BLEND);
  SDL_SetRenderDrawColor(context->renderer, 192, 192, 192, 255);
  SDL_RenderClear(context->renderer);
  SDL_RenderPresent(context->renderer);

  context->texture = load_texture(context->renderer, "assets/fields.bmp");
  if(context->texture == NULL) {
    fprintf(stderr, "Falha na inicialização da textura\n");
    return false;
  }
  SDL_SetTextureBlendMode(context->texture, SDL_BLENDMODE_BLEND);

  SDL_Texture *fields_texture = load_texture(context->renderer, "assets/fields.bmp");
  if(context->texture == NULL) {
    fprintf(stderr, "Falha na inicialização da textura\n");
    return false;
  }
  setup_tileset(&(context->field_states), fields_texture, 32, 32);

  SDL_Texture *cells_texture = load_texture(context->renderer, "assets/states.bmp");
  if(context->texture == NULL) {
    fprintf(stderr, "Falha na inicialização da textura\n");
    return false;
  }
  setup_tileset(&(context->cell_states), cells_texture, 32, 32);

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
  struct table *game = &(context->game);

  int figure_index[] = {
    ['*'] = 0,
    ['1'] = 2, ['2'] = 3, ['3'] = 4, ['4'] = 5,
    ['5'] = 6, ['6'] = 7, ['7'] = 8, ['8'] = 9
  };

  for(int i=0; i < context->game.rows; i++) {
    for(int j=0; j < context->game.cols; j++) {
      int index = i*game->cols+j;
      draw_tile(context->renderer,
        (*context).cell_states.tiles[game->digged[index]],
        32*j, 32*i);
      if((game->digged[index]) && (game->field[index] != '0')) {
        draw_tile(context->renderer,
          (*context).field_states.tiles[figure_index[(int)game->field[index]]],
          32*j, 32*i);
      }
    }
  }
  SDL_RenderPresent(context->renderer);
}

void clean_up(struct context *context) {
  free_context(context);

  SDL_Quit();
}