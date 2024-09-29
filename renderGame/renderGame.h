#ifndef RENDERGAME_H
#define RENDERGAME_H
#include "../tilemap/tilemap.h"
#include "../player/player.h"

void render_game(struct tilemap *tilemap, SDL_Renderer *renderer, struct player *p);

#endif

