

#ifndef TILEMAP_H
#define TILEMAP_H

#include "../dataStructures/matrix/matrix.h"
#include "../dataStructures/vec2d/vec2d.h"
#include "../objects/tile/tile.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <stdbool.h>
#include "../objects/grass/grass.h"
#include "../objects/tree/tree.h"

struct tilemap{
    int width;
    int height;
    int tile_size;
    struct matrix *mapMatrix;
    struct tileList *tileList;
};

struct tileList{
    struct Tile *tiles[48][72];
};

struct Tile{
    SDL_Rect posRect;
    bool hasCollision;
    void(*RenderFunction)(void* object, SDL_Renderer *renderer, struct vec2d playerPos);
    void* object;
};

void renderTile(struct Tile *tile, SDL_Renderer* renderer);

struct Tile* generateTile(SDL_Renderer* renderer, struct vec2d cords, int tile_type, int tile_size);

struct tileList* create_tile_list();

void generate_tilemap(SDL_Renderer *renderer, struct tilemap *tilemap);

struct tilemap *create_tilemap();

#endif
