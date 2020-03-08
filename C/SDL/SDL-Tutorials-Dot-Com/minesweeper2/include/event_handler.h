#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <SDL2/SDL.h>
#include "context.h"

void handle_event(struct context*, SDL_Event*);

#endif