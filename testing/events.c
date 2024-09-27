#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <stdbool.h>
#include <stdio.h>  // Include for printf
#include <sys/types.h>

bool init(SDL_Window **window,
          SDL_Surface **windowSurface,
          const char* title,
          int winHeight,
          int winWidth
          );

void handleErr();

void close_all(SDL_Window* window, SDL_Surface* surface);

int main() {
    bool quit = false;
    SDL_Event e;

    SDL_Window* window = NULL;
    SDL_Surface* windowSurface = NULL;
    int red, green, blue = 0;

    if (!init(&window, &windowSurface, "Cool", 480, 640)) {
        return 1; // Initialization failed
    }

    while (!quit) {
        // Get input from input poll
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            if (e.type == SDL_KEYDOWN){
                switch (e.key.keysym.sym){
                    case SDLK_r:
                        red++;
                        break;
                    case SDLK_g:
                        green++;
                        break;
                    case SDLK_b:
                        blue++;
                        break;
                }
            }
        }

        // Render screen
        SDL_FillRect(windowSurface, NULL,SDL_MapRGB(windowSurface->format, red, green, blue));
        SDL_UpdateWindowSurface(window);
    }

    close_all(window, windowSurface);
    return 0;
}

void handleErr() {
    printf("There was an error: %s\n", SDL_GetError()); // Added newline for better formatting
}

bool init(SDL_Window **window, SDL_Surface **windowSurface, const char* title, int winHeight, int winWidth) {
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        handleErr();
        success = false;
    } else {
        *window = SDL_CreateWindow(title,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  winWidth,
                                  winHeight,
                                  SDL_WINDOW_SHOWN);
        if (*window == NULL) {
            handleErr();
            success = false;
        } else {
            *windowSurface = SDL_GetWindowSurface(*window);
        }
    }
    return success;
}

void close_all(SDL_Window* window, SDL_Surface* surface) {
    if (surface) {
        SDL_FreeSurface(surface);
        surface = NULL; // Note: This won't affect the original pointer
    }

    if (window) {
        SDL_DestroyWindow(window);
        window = NULL; // Note: This won't affect the original pointer
    }

    SDL_Quit();
}

