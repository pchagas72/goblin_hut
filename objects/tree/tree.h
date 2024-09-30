

#ifndef TREE_H
#define TREE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include "../../dataStructures/vec2d/vec2d.h"
#include "../../textureManager/textureManager.h"

struct BirchTree{
    char* texturePath;
    SDL_Texture* texture; 
    SDL_Rect posRect;
    SDL_Rect srcRect; // Not implemented yet
};

void initBirchTree(struct BirchTree *tree, SDL_Renderer *renderer, int tile_size, struct vec2d cords);

void renderBirchTree(void* tree_data, SDL_Renderer* renderer,struct vec2d playerPos);

struct BirchTree* create_tree();

#endif
