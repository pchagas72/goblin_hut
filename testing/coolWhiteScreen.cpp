#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdbool.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int argc, char* args[]){
    SDL_Window* window = NULL;

    SDL_Surface* screenSurface = NULL;

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Oops, SDL error: %s\n",SDL_GetError());
    } else{
        window = SDL_CreateWindow("Goblin Hut", SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SCREEN_WIDTH,
                                  SCREEN_HEIGHT,
                                  SDL_WINDOW_SHOWN);
        if(window == NULL){
            printf("Window could not be creatd: %s\n",SDL_GetError());
        } else{
            screenSurface = SDL_GetWindowSurface(window);

            SDL_FillRect(screenSurface, NULL,
                         SDL_MapRGB(screenSurface->format,
                                    255, 255, 255));

            SDL_UpdateWindowSurface(window);

            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
