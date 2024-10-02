

#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL.h>
#include "../dataStructures/vec2d/vec2d.h"
#include "../collision/collision.h"
#include "../tilemap/tilemap.h"

struct player{
    SDL_Rect posRect;
    SDL_Texture *texture;
    int speed;
    struct vec2d dir;
    int angle;
    bool isColliding;
};

void LoadPlayerTexture(struct player *p, SDL_Renderer *renderer);

void handlePlayerInput(const Uint8 *keyState,
                       struct player *p,
                       int SCREEN_WIDTH,
                       int SCREEN_HEIGHT,
                       struct tilemap *map);

void initPlayer(struct player *p);

void renderPlayer(struct player *p, SDL_Renderer* renderer);

bool checkPlayerCollision(struct tilemap *map, SDL_Rect *ghost);

struct player *create_player();

#endif
