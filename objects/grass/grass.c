#include "./grass.h"
#include <SDL2/SDL_render.h>

struct Grass* create_grass() {
    struct Grass* grass = malloc(sizeof(struct Grass));
    if (!grass) {
        fprintf(stderr, "Failed to allocate memory for Grass\n");
        exit(EXIT_FAILURE);  // or handle it in another way
    }
    return grass;
}

void initGrass(struct Grass *grass, SDL_Renderer *renderer, int tile_size, struct vec2d pos){
    grass->texturePath = "sprites/grass.bmp";
    grass->steppedTexturePath = "sprites/tree.bmp";
    grass->texture = LoadTexture(grass->texturePath, renderer);
    grass->steppedTexture = LoadTexture(grass->steppedTexturePath, renderer);
    grass->posRect.x = pos.X*tile_size;
    grass->posRect.y = pos.Y*tile_size;
    grass->posRect.h = tile_size;
    grass->posRect.w = tile_size;
}

void renderGrass(void* grass_data, SDL_Renderer* renderer, struct vec2d playerPos) {
    struct Grass* grass = (struct Grass*)grass_data;
    if (grass->texture) { // Check if the texture is valid
        SDL_RenderCopy(renderer, grass->texture, NULL, &grass->posRect);
    } else {
        fprintf(stderr, "Texture not loaded for Grass at position (%d, %d)\n", grass->posRect.x, grass->posRect.y);
    }
}

void freeGrass(struct Grass* grass) {
    if (grass) {
        SDL_DestroyTexture(grass->texture);  // Free the texture if it was created
        SDL_DestroyTexture(grass->steppedTexture);
        free(grass);
    }
}
