#include "./grass.h"
#include <SDL2/SDL_render.h>

void initGrass(struct Grass *grass, SDL_Renderer *renderer){
    grass->texturePath = "sprites/grass.bmp";
    grass->texture = LoadTexture(grass->texturePath, renderer);
    grass->posRect.x = 0;
    grass->posRect.y = 0;
    grass->posRect.h = 10;
    grass->posRect.w = 10;
}

void renderGrass(struct Grass *grass, SDL_Renderer* renderer){
    SDL_RenderCopy(renderer,
                   grass->texture,
                   NULL,
                   &grass->posRect);
}

struct Grass* generateGrass(SDL_Renderer* renderer){
    struct Grass* grass = malloc(sizeof(struct Grass));
    initGrass(grass, renderer);
    return grass;
}
