#include "./game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

SDL_Window *window;
SDL_Renderer *renderer;

bool initWindow(const char *title,
                int xpos,
                int ypos,
                int width,
                int height,
                bool fullscreen){
    bool isRunning = false;
    int flags = SDL_WINDOW_SHOWN;
    if (fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_INIT_EVERYTHING < 0){
        printf("There was an error initializing SDL: %s",SDL_GetError());
    } else{
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags); 
        if (window < 0){
            printf("There was an error initializing window: %s",SDL_GetError());
        } else{
            renderer = SDL_CreateRenderer(window, -1, 0);
            if (renderer){
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                isRunning = true;
            } else{
                printf("There was an error initializing renderer: %s",SDL_GetError());
            }
        }
    }
    return isRunning;
}

void handeEvents(bool *isRunning){
    SDL_Event e;
    SDL_PollEvent(&e);
    switch (e.type){
        case SDL_QUIT:
            isRunning = false;
    }
}

void render(){
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void close_all(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
