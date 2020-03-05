#include "display_element.h"

SDL_Texture* load_texture(SDL_Renderer* renderer, char* file) {
  SDL_Texture* texture = NULL;
  SDL_Surface *surface = NULL;

  surface = SDL_LoadBMP(file);
  if(surface == NULL) {
    fprintf(stderr, "Algum erro impediu a imagem \"%s\" de carregar\n", file);
    texture = NULL;
    return NULL;
  }

  texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);

  if(texture == NULL) {
    fprintf(stderr, "Algum erro impediu a a textura de ser criada a partir de \"%s\"\n", file);
  }

  return texture;
}

bool draw_texture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y) {
  if(texture == NULL || renderer == NULL) {
    return false;
  }
  int width, height;

  SDL_QueryTexture(texture, NULL, NULL, &width, &height);

  SDL_Rect dest_rect = { .x = x, .y = y, .w = width, .h = height };

  SDL_RenderCopy(renderer, texture, NULL, &dest_rect);

  return true;
}

bool draw_partial_texture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, SDL_Rect *fragment) {
  if(texture == NULL || renderer == NULL) {
    return false;
  }

  SDL_Rect dest_rect = { .x = x, .y = y, .w = fragment->w, .h = fragment->h };

  SDL_RenderCopy(renderer, texture, fragment, &dest_rect);

  return true;
}