#ifndef TILESET_H
#define TILESET_H

#include<stdbool.h>
#include<SDL2/SDL.h>

#define TILESET_MAX_TILES 64

struct tileset {
  struct tile *tiles[TILESET_MAX_TILES];

  SDL_Texture *tiles_textures;
  SDL_Rect tile_rects[TILESET_MAX_TILES];

  int num_tiles;
  int tile_width;
  int tile_height;
};

struct tile {
  struct tileset *tileset;

  int texture_index;
  int width;
  int height;
};

void setup_tileset(struct tileset*, SDL_Texture*, int, int);

bool draw_tile(SDL_Renderer*, struct tile*, int, int);

void free_tileset(struct tileset*);

#endif