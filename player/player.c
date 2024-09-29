#include "player.h"
#include "../textureManager/textureManager.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <math.h>
#include <SDL2/SDL_rect.h>
#include <stdio.h>

void LoadPlayerTexture(struct player *p, SDL_Renderer *renderer){
    SDL_Texture* playerTexture = LoadTexture("sprites/player.bmp",
                                             renderer);
    p->texture = playerTexture;
}

void handlePlayerInput(const Uint8 *keyState,
                       struct player *p,
                       int SCREEN_WIDTH,
                       int SCREEN_HEIGHT,
                       SDL_Renderer *renderer){
    if (keyState[SDL_SCANCODE_W] && p->posRect.y - p->speed >= 0) {
        if (!p->isColliding) {
            p->dir.Y += -1;
        }
    }
    if (keyState[SDL_SCANCODE_S] && p->posRect.y + p->posRect.h + p->speed <= SCREEN_HEIGHT) {
        if (!p->isColliding) {
            p->dir.Y += 1;
        }
    }
    if (keyState[SDL_SCANCODE_A] && p->posRect.x - p->speed >= 0) {
        if (!p->isColliding) {
            p->dir.X += -1;
        }
    }
    if (keyState[SDL_SCANCODE_D] && p->posRect.x + p->posRect.w + p->speed <= SCREEN_WIDTH) {
        if (!p->isColliding) {
            p->dir.X += 1;
        }
    } 
    if (p->dir.X != 0 && p->dir.Y != 0) {
        p->posRect.x += p->dir.X*(p->speed*(1/sqrt(2)));
        p->posRect.y += p->dir.Y*(p->speed*(1/sqrt(2)));
    } else{
        p->posRect.x += (p->dir.X*p->speed);
        p->posRect.y += (p->dir.Y*p->speed);
    }

    if (p->dir.X == 0 && p->dir.Y == -1) {p->angle = 0;}
    if (p->dir.X == 0 && p->dir.Y == 1) {p->angle = 180;}
    if (p->dir.X == 1 && p->dir.Y == 0) {p->angle = 90;}
    if (p->dir.X == -1 && p->dir.Y == 0) {p->angle = 270;}
    if (p->dir.X == 1 && p->dir.Y == 1) {p->angle = 135;}
    if (p->dir.X == -1 && p->dir.Y == -1) {p->angle = 315;}
    if (p->dir.X == 1 && p->dir.Y == -1) {p->angle = 45;}
    if (p->dir.X == -1 && p->dir.Y == 1) {p->angle = 225;}

    p->dir.X = 0;
    p->dir.Y = 0;

    p->collisionRect.y = p->posRect.y;
    p->collisionRect.x = p->posRect.x;
    if (p->isColliding){
        printf("Im colliding bnitch");
    }
}

void initPlayer(struct player *p) {
    p->posRect.x = 1;
    p->posRect.y = 1;
    p->posRect.w = 32;
    p->posRect.h = 32;
    p->speed = 5;

    p->collisionRect.y = p->posRect.y;
    p->collisionRect.y = p->posRect.y;
    p->collisionRect.w = 33;
    p->collisionRect.h = 33;
}

void renderPlayer(struct player *p, SDL_Renderer* renderer){
    SDL_RenderCopyEx(renderer, p->texture, NULL, &p->posRect, p->angle, NULL, SDL_FLIP_NONE);
}

void checkPlayerCollision(struct Tile *tile, struct player *p){
    if (tile->hasCollision) {
        p->isColliding = SDL_HasIntersection(&tile->collisionRect, &p->collisionRect);
    }
}

void resetPlayerCollision(struct player *p){
    p->isColliding = false;
}

