#include "./tile.h"
#include <SDL2/SDL_render.h>

void initTile(struct Tile *tile, SDL_Renderer *renderer, char* texture_path, struct vec2d cords){
    tile->texturePath = "sprites/grass.bmp";
    tile->texture = LoadTexture(tile->texturePath, renderer);
    tile->posRect.x = cords.X;
    tile->posRect.y = cords.Y;
    tile->posRect.h = 10;
    tile->posRect.w = 10;
}

void renderTile(struct Tile *tile, SDL_Renderer* renderer){
    SDL_RenderCopy(renderer,
                   tile->texture,
                   NULL,
                   &tile->posRect);
}

struct Tile* generateTile(SDL_Renderer* renderer, struct vec2d cords, int tile_type){
    struct Tile* tile = malloc(sizeof(struct Tile));
    switch (tile_type) {
        case GRASS:
            tile->texture = LoadTexture(GRASS_TEXTURE, renderer);
        case TREE:
            tile->texture = LoadTexture(TREE_TEXTURE, renderer);
    }
    tile->posRect.x = cords.X * TILE_SIZE;
    tile->posRect.y = cords.Y * TILE_SIZE;
    tile->posRect.w = TILE_SIZE;
    tile->posRect.h = TILE_SIZE;
    return tile;
}
