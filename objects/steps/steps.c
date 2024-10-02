#include "./steps.h"
#include <SDL2/SDL_render.h>
#include <stdio.h>

struct Step* create_step() {
    struct Step* step = malloc(sizeof(struct Step));
    if (!step) {
        fprintf(stderr, "Failed to allocate memory for Steps\n");
        exit(EXIT_FAILURE); // Make this better 
    }
    return step;
}

void initSteps(struct Step *step, SDL_Renderer *renderer, int tile_size, struct vec2d pos){
    step->texturePath = "sprites/step.bmp";
    step->texture = LoadTexture(step->texturePath, renderer);
    step->posRect.x = pos.X*tile_size;
    step->posRect.y = pos.Y*tile_size;
    step->posRect.h = tile_size;
    step->posRect.w = tile_size;
}

void render_step(struct Step* step, SDL_Renderer* renderer, struct vec2d playerPos) {
    if (step->texture) { // Check if the texture is valid
        printf("Renderizando step em %d %d\n", playerPos.X, playerPos.Y);
        SDL_RenderCopy(renderer, step->texture, NULL, &step->posRect);
    } else {
        fprintf(stderr, "Texture not loaded for step at position (%d, %d)\n", step->posRect.x, step->posRect.y);
    }
}

void free_step(struct Step *step) {
    if (step) {
        SDL_DestroyTexture(step->texture); 
        free(step);
    }
}

struct Steps *create_steps(){
    struct Steps *steps = malloc(sizeof(struct Steps));
    return steps;
}

void render_steps(struct Steps *steps, SDL_Renderer *renderer, struct vec2d playerPos){
    for (int i = 0; i < steps->stepsCounter; i++){
        printf("Rendering step");
        render_step(steps->steps[i], renderer, playerPos);
    }
}

void free_all_steps(struct Steps *steps){
    for (int i = 0; i <= steps->stepsCounter; i++) {
        free_step(steps->steps[i]);
    } 
}
