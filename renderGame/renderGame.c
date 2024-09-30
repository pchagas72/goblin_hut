

#include "./renderGame.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

void render_game(struct tilemap *tilemap, SDL_Renderer *renderer, struct player *p) {
    struct Tile *curTile;
    struct vec2d PlayerCords = {p->posRect.x, p->posRect.y};
    for (int i = 0; i < tilemap->height; i++) {
        for (int j = 0; j < tilemap->width; j++) {
            curTile = tilemap->tileList->tiles[i][j];
            curTile->RenderFunction(curTile->object, renderer, PlayerCords);
        }
    }
    renderPlayer(p, renderer);
}


