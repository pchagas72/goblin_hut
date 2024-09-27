#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdbool.h>
#include "./player/player.h"
#include "./objects/tree/tree.h"
#include "textureManager/textureManager.h"
#include "dataStructures/vec2d/vec2d.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
int frameCounter = 0;

#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 480
#define FPS 60
#define FRAME_DELAY (1000/FPS)

bool initWindow(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

int main(int argc, char *argv[]) {
    // Create the window and set isRunning
    bool isFullScreen = false;
    bool isRunning = initWindow("Title",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                SCREEN_WIDTH,
                                SCREEN_HEIGHT,
                                false);


    // Create player and initialize it
    struct player p;
    LoadPlayerTexture(&p, renderer);
    initPlayer(&p);

    // Check if ok before initializing game loop
    if (!isRunning) {
        return -1;
    }

    // Initialize game tick
    Uint32 frameStart;
    int frameTime;

    
    // TESTING STUFF
    struct BirchTree tree;
    struct vec2d cords;
    cords.X = 100;
    cords.Y = 100;
    initBirchTree(&tree, renderer, cords);

    struct BirchTree otherTree;
    struct vec2d otherCords;
    otherCords.X = 300;
    otherCords.Y = 300;
    initBirchTree(&otherTree, renderer, otherCords);
    //
    // INITIALIZING GAME LOOP HERE
    //
    while (isRunning) {
        frameStart = SDL_GetTicks(); 


        // Get input
        SDL_Event e;

        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                isRunning = false;
            }
        }

        // Update
        frameCounter++;

        // Player fluid movement
        const Uint8 *keyState = SDL_GetKeyboardState(NULL);
        handlePlayerInput(keyState, &p, SCREEN_WIDTH, SCREEN_HEIGHT);

        // render
        SDL_RenderClear(renderer);
        // Render map
        renderBirchTree(&tree, renderer);
        renderBirchTree(&otherTree, renderer);
        // Render player
        renderPlayer(&p, renderer);
        SDL_RenderPresent(renderer);

        // Calculate time of frame
        frameTime = SDL_GetTicks() - frameStart;

        if (FRAME_DELAY > frameTime){
            SDL_Delay(FRAME_DELAY - frameTime);
        }
    }

    if (p.texture) {
        SDL_DestroyTexture(p.texture);
    }
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
    if (window) {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
    return 0;
}

bool initWindow(const char *title,
                int xpos,
                int ypos,
                int width,
                int height,
                bool fullscreen) {
    bool isRunning = false;
    int flags = SDL_WINDOW_SHOWN;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {  // Corrected condition
        printf("There was an error initializing SDL: %s\n", SDL_GetError());
    } else {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window == NULL) {  // Corrected window check
            printf("There was an error initializing window: %s\n", SDL_GetError());
        } else {
            renderer = SDL_CreateRenderer(window, -1, 0);
            if (renderer) {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                isRunning = true;
            } else {
                printf("There was an error initializing renderer: %s\n", SDL_GetError());
            }
        }
    }
    return isRunning;
}
