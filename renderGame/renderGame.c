#include "./renderGame.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

void render_game(struct tilemap *tilemap, SDL_Renderer *renderer, struct player *p) {
    for (int i = 0; i < tilemap->height; i++) {
        for (int j = 0; j < tilemap->width; j++) {
            renderTile(tilemap->tileList->tiles[i][j], renderer);
        }
    }
    renderPlayer(p, renderer);
}


