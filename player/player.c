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

    if (p->isColliding){
        printf("I colided");
    }

    bool change_sprite = true;

    if (keyState[SDL_SCANCODE_W] && p->posRect.y - p->speed >= 0) {
        if (!p->isColliding){
            p->dir.Y += -1;
        } else{
            p->dir.Y += 1;
            change_sprite = false;
        }
    }
    if (keyState[SDL_SCANCODE_S] && p->posRect.y + p->posRect.h + p->speed <= SCREEN_HEIGHT) {
        if (!p->isColliding){
            p->dir.Y += 1;
        } else{
            p->dir.Y -= 1;
            change_sprite = false;
        }
    }
    if (keyState[SDL_SCANCODE_A] && p->posRect.x - p->speed >= 0) {
        if (!p->isColliding){
            p->dir.X += -1;
        } else{
            p->dir.X += 1;
            change_sprite = false;
        }
    }
    if (keyState[SDL_SCANCODE_D] && p->posRect.x + p->posRect.w + p->speed <= SCREEN_WIDTH) {
        if (!p->isColliding){
            p->dir.X += 1;
        } else{
            p->dir.X -= 1;
            change_sprite = false;
        }
    } 
    if (p->dir.X != 0 && p->dir.Y != 0) {
        p->posRect.x += p->dir.X*(p->speed*(1/sqrt(2)));
        p->posRect.y += p->dir.Y*(p->speed*(1/sqrt(2)));
    } else{
        p->posRect.x += (p->dir.X*p->speed);
        p->posRect.y += (p->dir.Y*p->speed);
    }

    if (p->dir.X == 0 && p->dir.Y == -1 && change_sprite) {p->angle = 0;}
    if (p->dir.X == 0 && p->dir.Y == 1 && change_sprite) {p->angle = 180;}
    if (p->dir.X == 1 && p->dir.Y == 0 && change_sprite) {p->angle = 90;}
    if (p->dir.X == -1 && p->dir.Y == 0 && change_sprite) {p->angle = 270;}
    if (p->dir.X == 1 && p->dir.Y == 1 && change_sprite) {p->angle = 135;}
    if (p->dir.X == -1 && p->dir.Y == -1 && change_sprite) {p->angle = 315;}
    if (p->dir.X == 1 && p->dir.Y == -1 && change_sprite) {p->angle = 45;}
    if (p->dir.X == -1 && p->dir.Y == 1 && change_sprite) {p->angle = 225;}

    p->dir.X = 0;
    p->dir.Y = 0;
}

void initPlayer(struct player *p) {
    p->posRect.x = 30;
    p->posRect.y = 30;
    p->posRect.w = 32;
    p->posRect.h = 32;
    p->speed = 5;
}

void renderPlayer(struct player *p, SDL_Renderer* renderer){
    SDL_RenderCopyEx(renderer, p->texture, NULL, &p->posRect, p->angle, NULL, SDL_FLIP_NONE);
}

