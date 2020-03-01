#ifndef DISPLAY_ELEMENT_H
#define DISPLAY_ELEMENT_H

#include <SDL2/SDL.h>
#include <stdbool.h>

SDL_Texture* load(SDL_Renderer*, char*);

bool draw_texture(SDL_Texture*, SDL_Renderer*, int , int);

bool draw_partial_texture(SDL_Texture*, SDL_Renderer*, int, int, SDL_Rect*);

#endif