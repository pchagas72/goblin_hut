#include "./tilemap.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <stdio.h>

struct tileList* create_tile_list(){
    struct tileList *tiles = malloc(sizeof(struct tileList));
    return tiles;
}
void generate_tilemap(SDL_Renderer *renderer,struct tilemap *tilemap){
    struct tileList *tiles = create_tile_list();
    for (int i = 0; i < tilemap->height; i++) {
        for (int j = 0; j < tilemap->width; j++) {
            struct vec2d pos = {j, i};  // Note: (x, y) is (j, i) is (row, column)
            int tile_type = tilemap->mapMatrix->content[i][j];
            struct Tile *tile = generateTile(renderer, pos, tile_type, tilemap->tile_size);
            tiles->tiles[i][j] = tile;
            printf("%d",j);
        }
    }
    tilemap->tileList = tiles;
}

void renderTile(struct Tile *tile, SDL_Renderer* renderer){
    SDL_RenderCopy(renderer,
                   tile->texture,
                   NULL,
                   &tile->posRect);
}

struct Tile* generateTile(SDL_Renderer* renderer, struct vec2d cords, int tile_type, int tile_size){
    struct Tile* tile = malloc(sizeof(struct Tile));
    switch (tile_type) {
        case GRASS:
            tile->texture = LoadTexture(GRASS_TEXTURE, renderer);
            tile->hasCollision = false;
            break;
        case TREE:
            tile->texture = LoadTexture(TREE_TEXTURE, renderer);
            tile->hasCollision = true;
            break;
    }
    tile->posRect.x = cords.X * tile_size;
    tile->posRect.y = cords.Y * tile_size;
    tile->posRect.w = tile_size;
    tile->posRect.h = tile_size;
    tile->collisionRect.x = tile->posRect.x;
    tile->collisionRect.y = tile->posRect.y;
    tile->collisionRect.w = tile_size;
    tile->collisionRect.h = tile_size;
    return tile;
}
