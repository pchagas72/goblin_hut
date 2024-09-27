

#include "./textureManager.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

 SDL_Texture* LoadTexture(const char *fileName, SDL_Renderer *renderer){
    SDL_Surface *tmpSurface = SDL_LoadBMP(fileName);
    SDL_Texture* texture = NULL;

    if (tmpSurface == NULL) {
        printf("Failed to load BMP: %s\n", SDL_GetError());
    }

    texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    if (texture == NULL) {
        printf("Failed to create texture: %s\n", SDL_GetError());
    }
    return texture;
}
