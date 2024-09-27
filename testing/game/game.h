#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <stdbool.h>


bool initWindow(const char *title,
                int xpos,
                int ypos,
                int width,
                int height,
                bool fullscreen);

void handleEvents(bool *isRunning);

void render();

void close_all();
