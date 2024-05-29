#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

typedef struct sdl_s {
    SDL_Window *window;
} sdl_t;

typedef struct sizew_s {
    uint8_t Win_width;
    uint8_t Win_height;
} sizew_t;

bool init(sdl_t *sdl, const sizew_t *s)
{
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
        SDL_Log("SLD n'est pas initialiser! %s\n", SDL_GetError());
        return false;
    }
    sdl->window = SDL_CreateWindow("Chip 8 experimentation",
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    s->Win_width, s->Win_height,
                                    0);
    if (!sdl->window) {
        SDL_Log("SDL window de peut pas etre cree %s\n", SDL_GetError());
        return false;
    }
    return true;
}

void cleanup(sdl_t *sdl)
{
    SDL_DestroyWindow(sdl->window);
    SDL_Quit();
}

int main(void)
{
    sdl_t sdl = {0};
    sizew_t s = {0};

    if (!init(&sdl, &s))
        exit(EXIT_FAILURE);
    cleanup(&sdl);
    exit(EXIT_SUCCESS);
}
