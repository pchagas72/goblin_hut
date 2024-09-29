#include "./renderGame.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

void render_game(struct tilemap *tilemap, SDL_Renderer *renderer, struct player *p) {
    struct Tile *curTile;
    p->isColliding = false;
    for (int i = 0; i < tilemap->height; i++) {
        for (int j = 0; j < tilemap->width; j++) {
            curTile = tilemap->tileList->tiles[i][j];
            renderTile(curTile, renderer);
            if (SDL_HasIntersection(&p->posRect, &curTile->posRect) && curTile->hasCollision) {
                p->isColliding = true; 
            }
        }
    }
    renderPlayer(p, renderer);
}


