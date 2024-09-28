

#ifndef TILEMAP_H
#define TILEMAP_H

#include "../dataStructures/matrix/matrix.h"
#include "../dataStructures/vec2d/vec2d.h"
#include "../objects/grass/grass.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

struct tilemap{
    int width;
    int height;
    struct matrix *mapMatrix;
};

void render_tilemap(struct tilemap *tilemap, SDL_Renderer *renderer);

void render_tilemap_objects(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect *posRect); 

#endif
