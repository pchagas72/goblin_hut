#include "player.h"
#include "../textureManager/textureManager.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

void LoadPlayerTexture(struct player *p, SDL_Renderer *renderer){
    SDL_Texture* playerTexture = LoadTexture("sprites/player.bmp",
                                             renderer);
    p->texture = playerTexture;
}

void handlePlayerInput(const Uint8 *keyState, struct player *p, int SCREEN_WIDTH, int SCREEN_HEIGHT){
    if (keyState[SDL_SCANCODE_W] && p->posRect.y - p->speed >= 0) {
        p->posRect.y -= p->speed;
    }
    if (keyState[SDL_SCANCODE_S] && p->posRect.y + p->posRect.h + p->speed <= SCREEN_HEIGHT) {
        p->posRect.y += p->speed;
    }
    if (keyState[SDL_SCANCODE_A] && p->posRect.x - p->speed >= 0) {
        p->posRect.x -= p->speed;
    }
    if (keyState[SDL_SCANCODE_D] && p->posRect.x + p->posRect.w + p->speed <= SCREEN_WIDTH) {
        p->posRect.x += p->speed;
    } 
}

void initPlayer(struct player *p) {
    p->posRect.x = 1;
    p->posRect.y = 1;
    p->posRect.w = 32;
    p->posRect.h = 32;
    p->speed = 5;
}

void renderPlayer(struct player *p, SDL_Renderer* renderer){
    SDL_RenderCopy(renderer, p->texture, NULL, &p->posRect);
}
