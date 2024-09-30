#ifndef GRASS_H
#define GRASS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include "../../dataStructures/vec2d/vec2d.h"
#include "../../textureManager/textureManager.h"

struct Grass{
    char* texturePath;
    char* steppedTexturePath;
    SDL_Texture* texture; 
    SDL_Texture* steppedTexture; 
    SDL_Rect posRect;
    SDL_Rect srcRect; // Not implemented yet
};

struct Grass* create_grass();

void initGrass(struct Grass *grass, SDL_Renderer *renderer, int tile_size, struct vec2d pos);

void renderGrass(void *data, SDL_Renderer* renderer, struct vec2d playerPos);

//void checkStepped(struct Grass *grass, struct player *p);

#endif
