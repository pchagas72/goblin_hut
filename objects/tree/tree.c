#include "./tree.h"
#include <SDL2/SDL_render.h>

void initBirchTree(struct BirchTree *tree, SDL_Renderer *renderer, struct vec2d cords){
    tree->texturePath = "sprites/tree.bmp";
    tree->texture = LoadTexture(tree->texturePath, renderer);
    tree->posRect.x = cords.X;
    tree->posRect.y = cords.Y;
    tree->posRect.h = 10;
    tree->posRect.w = 10;
}

void renderBirchTree(struct BirchTree *tree, SDL_Renderer* renderer){
    SDL_RenderCopy(renderer,
                   tree->texture,
                   NULL,
                   &tree->posRect);
}
