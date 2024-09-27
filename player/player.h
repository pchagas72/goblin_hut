

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL.h>

struct player{
    SDL_Rect posRect;
    SDL_Texture *texture;
    int speed;
};

void LoadPlayerTexture(struct player *p, SDL_Renderer *renderer);

void handlePlayerInput(const Uint8 *keyState, struct player *p, int SCREEM_WIDTH, int SCREEN_HEIGHT);

void initPlayer(struct player *p);

void renderPlayer(struct player *p, SDL_Renderer* renderer);
