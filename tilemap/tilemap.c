#include "./tilemap.h"

void render_tilemap(struct tilemap *tilemap, SDL_Renderer *renderer) {

    struct Grass grass;

    for (int i = 0; i < tilemap->height; i++) {
        for (int j = 0; j < tilemap->width; j++) {
            struct vec2d pos = {j, i};  // Note: (x, y) is (column, row)
            printf("I: %d | J: %d | OBJ:%d \n", i, j, tilemap->mapMatrix->content[i][j]);
        }
    }
}

void render_tilemap_objects(int object_id, SDL_Renderer *renderer, struct vec2d pos) {
}
