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
        }
    }
    tilemap->tileList = tiles;
}

struct Tile* generateTile(SDL_Renderer* renderer, struct vec2d cords, int tile_type, int tile_size){
    struct Tile* tile = malloc(sizeof(struct Tile));
    if (tile == NULL){
        fprintf(stderr, "Failed to allocate memory for tile\n");
        return NULL;
    }
    if (tile_type == GRASS) {
        struct Grass *grass = create_grass(); 
        if (grass == NULL){
            fprintf(stderr, "Failed to create grass\n");
            free(tile);
            return NULL;
        }
        initGrass(grass, renderer, tile_size, cords);
        tile->RenderFunction = renderGrass;
        tile->object = (void*)grass;
        tile->hasCollision = false;
    } else if (tile_type == TREE){
        struct BirchTree* tree = create_tree();
        if (tree == NULL){
            fprintf(stderr, "Failed to create tree\n");
            free(tile);
            return NULL;
        }
        initBirchTree(tree, renderer, tile_size, cords);
        tile->RenderFunction = renderBirchTree;
        tile->object = (void*)tree;
        tile->hasCollision = true;
    }
    tile->posRect.h = tile_size;
    tile->posRect.w = tile_size;
    tile->posRect.x = cords.X*tile_size;
    tile->posRect.y = cords.Y*tile_size;
    return tile;
}

struct tilemap *create_tilemap(){
    struct tilemap *map = malloc(sizeof(struct tilemap));
    return map;
}
