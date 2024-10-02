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

struct player *create_player(){
    struct player *p = malloc(sizeof(struct player));
    return p;
}

void handlePlayerInput(const Uint8 *keyState,
                       struct player *p,
                       int SCREEN_WIDTH,
                       int SCREEN_HEIGHT,
                       struct tilemap *map,
                       SDL_Renderer *renderer) {

    bool change_sprite = true;
    bool has_moved = false;
    SDL_Rect playerGhostX = p->posRect; 
    SDL_Rect playerGhostY = p->posRect; 

    // Process input and movement
    if (keyState[SDL_SCANCODE_W] && p->posRect.y - p->speed >= 0) {
        p->dir.Y += -1;
        has_moved = true;
    }
    if (keyState[SDL_SCANCODE_S] && p->posRect.y + p->posRect.h + p->speed <= SCREEN_HEIGHT) {
        p->dir.Y += 1;
        has_moved = true;
    }
    if (keyState[SDL_SCANCODE_A] && p->posRect.x - p->speed >= 0) {
        p->dir.X += -1;
        has_moved = true;
    }
    if (keyState[SDL_SCANCODE_D] && p->posRect.x + p->posRect.w + p->speed <= SCREEN_WIDTH) {
        p->dir.X += 1;
        has_moved = true;
    }

    if (p->dir.X != 0 && p->dir.Y != 0) {
        playerGhostX.x += p->dir.X * (p->speed * (1 / sqrt(2)));
        playerGhostY.y += p->dir.Y * (p->speed * (1 / sqrt(2)));
    } else {
        playerGhostX.x += (p->dir.X * p->speed);
        playerGhostY.y += (p->dir.Y * p->speed);
    }

    if (!checkPlayerCollision(map, &playerGhostX, p)) {
        p->posRect.x = playerGhostX.x;  
    }

    if (!checkPlayerCollision(map, &playerGhostY, p)) {
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

    if (p->isStepping->type == GRASS) {
        printf("I'm stepping on grass\n");
    }
    if (p->isStepping->type == TREE) {
        printf("I'm stepping on tree\n");
    }

}


void initPlayer(struct player *p) {
    p->posRect.x = 40;
    p->posRect.y = 40;
    p->posRect.w = 32;
    p->posRect.h = 32;
    p->speed = 5;
    p->steps = create_steps();
    p->steps->stepsCounter = 0;
}

void renderPlayer(struct player *p, SDL_Renderer* renderer){
    SDL_RenderCopyEx(renderer, p->texture, NULL, &p->posRect, p->angle, NULL, SDL_FLIP_NONE);
    struct vec2d pos;
    pos.X = p->posRect.x;
    pos.Y = p->posRect.y;
    render_steps(p->steps, renderer, pos);
}

bool checkPlayerCollision(struct tilemap *map, SDL_Rect *ghost, struct player *p){
    struct Tile *tile;
    for (int y = 0; y < map->height; y++){
        for (int x = 0; x < map->width; x++){
            tile = map->tileList->tiles[y][x];
                if (SDL_HasIntersection(ghost, &tile->posRect) && tile->hasCollision){
                    p->isStepping = tile;
                    return true;
                } else if (SDL_HasIntersection(ghost, &tile->posRect)){
                    p->isStepping = tile;
                }
        }
    }
    return false;
}

void leaveSteps(struct player *p, SDL_Renderer *renderer){
    struct vec2d stepPos;
    if (p->steps->stepsCounter == 0) {
        struct Step *newStep;
        struct vec2d playerPos;
        playerPos.X = p->posRect.x;
        playerPos.Y = p->posRect.y;
        initSteps(newStep, renderer, 30, playerPos);
        p->steps->steps[p->steps->stepsCounter] = newStep;
        p->steps->stepsCounter++;
    }
    for (int i = 0; i < p->steps->stepsCounter; i++) {
        stepPos.X = p->steps->steps[i]->posRect.x;
        stepPos.Y = p->steps->steps[i]->posRect.y;
        if (abs(p->posRect.x-stepPos.X) < 50 && abs(p->posRect.y-stepPos.Y) < 50){
            printf("Ai o %d\n",abs(p->posRect.x-stepPos.X));
            //struct Step *newStep;
            //struct vec2d playerPos;
            //playerPos.X = p->posRect.x;
            //playerPos.Y = p->posRect.y;
            //initSteps(newStep, renderer, 30, playerPos);
            //p->steps->steps[p->steps->stepsCounter+1] = newStep;
            //p->steps->stepsCounter++;
        }

    }
}

















