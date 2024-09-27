#include "./grass.h"
#include <SDL2/SDL_render.h>

void initGrass(struct Grass *grass, SDL_Renderer *renderer, struct vec2d cords){
    grass->texturePath = "sprites/grass.bmp";
    grass->texture = LoadTexture(grass->texturePath, renderer);
    grass->posRect.x = cords.X;
    grass->posRect.y = cords.Y;
    grass->posRect.h = 10;
    grass->posRect.w = 10;
}

void renderGrass(struct Grass *grass, SDL_Renderer* renderer){
    SDL_RenderCopy(renderer,
                   grass->texture,
                   NULL,
                   &grass->posRect);
}
