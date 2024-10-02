

#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL.h>
#include "../dataStructures/vec2d/vec2d.h"
#include "../tilemap/tilemap.h"
#include "../objects/steps/steps.h"

struct player{
    SDL_Rect posRect;
    SDL_Texture *texture;
    int speed;
    struct vec2d dir;
    int angle;
    bool isColliding;
    bool leaveSteps;
    struct Steps *steps;
    struct Tile *isStepping;
};

void LoadPlayerTexture(struct player *p, SDL_Renderer *renderer);

void handlePlayerInput(const Uint8 *keyState,
                       struct player *p,
                       int SCREEN_WIDTH,
                       int SCREEN_HEIGHT,
                       struct tilemap *map,
                       SDL_Renderer *renderer);

void initPlayer(struct player *p);

void renderPlayer(struct player *p, SDL_Renderer* renderer);

bool checkPlayerCollision(struct tilemap *map, SDL_Rect *ghost, struct player *p);

struct player *create_player();

void leaveSteps(struct player *p, SDL_Renderer *renderer);

#endif
