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
                       struct tilemap *map) {

    bool change_sprite = true;
    SDL_Rect playerGhostX = p->posRect; 
    SDL_Rect playerGhostY = p->posRect; 

    // Process input and movement
    if (keyState[SDL_SCANCODE_W] && p->posRect.y - p->speed >= 0) {
        p->dir.Y += -1;
    }
    if (keyState[SDL_SCANCODE_S] && p->posRect.y + p->posRect.h + p->speed <= SCREEN_HEIGHT) {
        p->dir.Y += 1;
    }
    if (keyState[SDL_SCANCODE_A] && p->posRect.x - p->speed >= 0) {
        p->dir.X += -1;
    }
    if (keyState[SDL_SCANCODE_D] && p->posRect.x + p->posRect.w + p->speed <= SCREEN_WIDTH) {
        p->dir.X += 1;
    }

    if (p->dir.X != 0 && p->dir.Y != 0) {
        playerGhostX.x += p->dir.X * (p->speed * (1 / sqrt(2)));
        playerGhostY.y += p->dir.Y * (p->speed * (1 / sqrt(2)));
    } else {
        playerGhostX.x += (p->dir.X * p->speed);
        playerGhostY.y += (p->dir.Y * p->speed);
    }

    if (!checkPlayerCollision(map, &playerGhostX)) {
        p->posRect.x = playerGhostX.x;  
    }

    if (!checkPlayerCollision(map, &playerGhostY)) {
        p->posRect.y = playerGhostY.y; 
    }

    if (p->dir.X == 0 && p->dir.Y == -1 && change_sprite) { p->angle = 0; }
    if (p->dir.X == 0 && p->dir.Y == 1 && change_sprite) { p->angle = 180; }
    if (p->dir.X == 1 && p->dir.Y == 0 && change_sprite) { p->angle = 90; }
    if (p->dir.X == -1 && p->dir.Y == 0 && change_sprite) { p->angle = 270; }
    if (p->dir.X == 1 && p->dir.Y == 1 && change_sprite) { p->angle = 135; }
    if (p->dir.X == -1 && p->dir.Y == -1 && change_sprite) { p->angle = 315; }
    if (p->dir.X == 1 && p->dir.Y == -1 && change_sprite) { p->angle = 45; }
    if (p->dir.X == -1 && p->dir.Y == 1 && change_sprite) { p->angle = 225; }

    p->dir.X = 0;
    p->dir.Y = 0;
}


void initPlayer(struct player *p) {
    p->posRect.x = 40;
    p->posRect.y = 40;
    p->posRect.w = 32;
    p->posRect.h = 32;
    p->speed = 5;
}

void renderPlayer(struct player *p, SDL_Renderer* renderer){
    SDL_RenderCopyEx(renderer, p->texture, NULL, &p->posRect, p->angle, NULL, SDL_FLIP_NONE);
}

bool checkPlayerCollision(struct tilemap *map, SDL_Rect *ghost){
    SDL_Rect tileRect;
    for (int y = 0; y < map->height; y++){
        for (int x = 0; x < map->width; x++){
            tileRect = map->tileList->tiles[y][x]->posRect;
            if (map->tileList->tiles[y][x]->hasCollision){
                if (SDL_HasIntersection(ghost, &tileRect)){
                    return true;
                }
            }
        }
    }
    return false;
}
