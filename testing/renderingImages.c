#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_thread.h>
#include <SDL2/SDL_video.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

bool init();

bool loadMedia();

void close_all();

SDL_Window* gWindow = NULL;

SDL_Surface* gScreenSurface = NULL;

SDL_Surface* gHelloWorld = NULL; // Image data type, cool

bool init(){
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL could not start: %s", SDL_GetError());
        success = false;
    } else {
        gWindow = SDL_CreateWindow(
            "Hello World",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            640,
            480,
            SDL_WINDOW_SHOWN);
        if (gWindow == NULL){
            printf("Could not create window: %s",SDL_GetError());
            success = false;
        } else{
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }

    return success;
}

bool loadMedia(){
    bool success = true;

    gHelloWorld = SDL_LoadBMP("files/helloWorld.bmp");
    if( gHelloWorld == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/helloWorld.bmp", SDL_GetError() );
        success = false;
    }
    return success;
}

void close_all(){
    SDL_FreeSurface(gHelloWorld);
    gHelloWorld = NULL;

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    SDL_Quit();
}

int main(int argc, char* args[]){
    if (!init()){
        printf("Failed to initialize!\n");
    } else{
        if (!loadMedia()){
            printf("Failed to load media!!\n");
        }else{
            SDL_BlitSurface(gHelloWorld,NULL,gScreenSurface,NULL);
            SDL_UpdateWindowSurface(gWindow);
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
        }
    }
    close_all();
    return 0;
}
