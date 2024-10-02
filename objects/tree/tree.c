#include "./tree.h"
#include <SDL2/SDL_render.h>

struct BirchTree* create_tree(){
    struct BirchTree* tree = malloc(sizeof(struct BirchTree));
    if (!tree) {
        fprintf(stderr, "Failed to allocate memory for Tree\n");
        exit(EXIT_FAILURE);  // or handle it in another way
    }
        return tree;
}

void initBirchTree(struct BirchTree *tree, SDL_Renderer *renderer,int tile_size, struct vec2d cords){
    tree->texturePath = "sprites/tree.bmp";
    tree->texture = LoadTexture(tree->texturePath, renderer);
    tree->posRect.x = cords.X*tile_size;
    tree->posRect.y = cords.Y*tile_size;
    tree->posRect.h = tile_size;
    tree->posRect.w = tile_size;
}

void renderBirchTree(void* tree_data, SDL_Renderer* renderer, struct vec2d playerPos){
    struct BirchTree* tree = (struct BirchTree*)tree_data;
    if (tree->texture){
        SDL_RenderCopy(renderer,
                   tree->texture,
                   NULL,
                   &tree->posRect);
    } else{
        fprintf(stderr, "Texture not loaded for Tree at position (%d, %d)\n", tree->posRect.x, tree->posRect.y);
    }
}

void free_tree(void *data) {
    struct BirchTree *tree = data;
    if (tree) {
        SDL_DestroyTexture(tree->texture);  // Free the texture if it was created
        free(tree);
    }
}
