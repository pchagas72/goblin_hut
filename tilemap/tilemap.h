

#ifndef TILEMAP_H
#define TILEMAP_H

#include "../dataStructures/matrix/matrix.h"
#include "../dataStructures/vec2d/vec2d.h"
#include "../objects/tile/tile.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <stdbool.h>

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
    char* texturePath;
    SDL_Texture* texture; 
    SDL_Rect posRect;
    SDL_Rect srcRect; // Not implemented yet
    SDL_Rect collisionRect;
    bool hasCollision;
};

void renderTile(struct Tile *tile, SDL_Renderer* renderer);

struct Tile* generateTile(SDL_Renderer* renderer, struct vec2d cords, int tile_type, int tile_size);

struct tileList* create_tile_list();

void generate_tilemap(SDL_Renderer *renderer, struct tilemap *tilemap);

#endif
