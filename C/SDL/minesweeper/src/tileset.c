#include "tileset.h"
#include "display_element.h"

void setup_tile(struct tile *tile, struct tileset *tileset, int tindex) {
  tile->tileset = tileset;
  tile->texture_index = tindex;
  tile->width = tileset->tile_width;
  tile->height = tileset->tile_height;
}

void setup_tileset(struct tileset *tileset, SDL_Texture *texture, int wtile, int htile) {
  tileset->tile_width = wtile;
  tileset->tile_height = htile;
  tileset->tiles_textures = texture;

  int wtileset, htileset;
  SDL_QueryTexture(texture, NULL, NULL, &wtileset, &htileset);
  int row_tiles = htileset / htile;
  int col_tiles = wtileset / wtile;

  tileset->num_tiles = row_tiles * col_tiles;

  for(int i = 0; i < row_tiles; i++) {
    for(int j = 0; j < col_tiles; j++) {
      int index = i*col_tiles + j;
      SDL_Rect tile_rect = { .x = wtile*j, .y = htile*i, .w = wtile, .h = htile };

      tileset->tile_rects[index] = tile_rect;
      tileset->tiles[index] = (struct tile*) malloc(sizeof(struct tile));
      setup_tile((*tileset).tiles[index], tileset, index);
    }
  }
}

bool draw_tile(SDL_Renderer* renderer, struct tile *tile, int x, int y) {
  struct tileset *tileset = tile->tileset;
  SDL_Rect *rect = &(*tileset).tile_rects[tile->texture_index];

  return draw_partial_texture(
    tileset->tiles_textures,
    renderer, x, y,
    rect
  );
}

void free_tileset(struct tileset *tileset) {
  SDL_DestroyTexture(tileset->tiles_textures);

  for(int i=0; i<tileset->num_tiles; i++) {
    free(tileset->tiles[i]);
  }
}