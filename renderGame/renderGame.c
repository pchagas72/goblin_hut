#include "./renderGame.h"
#include <SDL2/SDL_rect.h>

void render_game(struct tilemap *tilemap, SDL_Renderer *renderer, struct player *p) {
    SDL_Rect tile_rect;
    SDL_Rect player_rect;
    for (int i = 0; i < tilemap->height; i++) {
        for (int j = 0; j < tilemap->width; j++) {
            renderTile(tilemap->tileList->tiles[i][j], renderer);
            tile_rect = tilemap->tileList->tiles[i][j]->posRect;
            player_rect = p->posRect;
            if (SDL_HasIntersection(&tile_rect, &player_rect) && tilemap->tileList->tiles[i][j]->hasCollision) {
                printf("Collision!");
            }
            checkPlayerCollision(tilemap->tileList->tiles[i][j], p);

        }
    }
    renderPlayer(p, renderer);
}


