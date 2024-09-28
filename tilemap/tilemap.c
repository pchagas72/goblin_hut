#include "./tilemap.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

void render_tilemap(struct tilemap *tilemap, SDL_Renderer *renderer) {
    for (int i = 0; i < tilemap->height; i++) {
        for (int j = 0; j < tilemap->width; j++) {
            struct vec2d pos = {i, j};  // Note: (x, y) is (column, row)
            printf("I: %d | J: %d | OBJ:%d \n", i, j, tilemap->mapMatrix->content[i][j]);
        }
    }
}

void generate_tilemap_objects(struct tilemap *tilemap){
    // This function will be called once per map
    // Create GENERIC LINKED LIST to hold all the different tiles
    // This facilitates keeping track of all tiles
}

void render_tilemap_objects(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect* posRect) {
    // Render objects acoording to generic linked list
}
