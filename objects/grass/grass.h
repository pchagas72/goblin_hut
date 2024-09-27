

#ifndef GRASS_H
#define GRASS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include "../../dataStructures/vec2d/vec2d.h"
#include "../../textureManager/textureManager.h"

struct Grass{
    char* texturePath;
    SDL_Texture* texture; 
    SDL_Rect posRect;
    SDL_Rect srcRect; // Not implemented yet
};

void initGrass(struct Grass *tree, SDL_Renderer *renderer, struct vec2d cords);

void renderGrass(struct Grass *tree, SDL_Renderer* renderer);

#endif
