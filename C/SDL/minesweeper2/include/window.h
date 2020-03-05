#ifndef WINDOW_H
#define WINDOW_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "context.h"

int execute(struct context*);

bool init(struct context*);

void event_handler(struct context*, SDL_Event*);

void loop(struct context*);

void render(struct context*);

void clean_up(struct context*);

#endif