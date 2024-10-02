

#ifndef STEPS_H
#define STEPS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include "../../dataStructures/vec2d/vec2d.h"
#include "../../textureManager/textureManager.h"

struct Step{
    char* texturePath;
    SDL_Texture* texture; 
    SDL_Texture* steppedTexture; 
    SDL_Rect posRect;
};

struct Steps{
    struct Step *steps[30*sizeof(struct Step)];
    int stepsCounter;
    int framesSinceLastStep;
};


struct Step* create_step();

void initSteps(struct Step *step, SDL_Renderer *renderer, int tile_size, struct vec2d pos);

void render_step(struct Step* step, SDL_Renderer* renderer, struct vec2d playerPos);

void free_step(struct Step *step);

struct Steps *create_steps();

void render_steps(struct Steps *steps, SDL_Renderer *renderer, struct vec2d playerPos);

#endif
