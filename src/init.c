#include "../include/chip8.h"

bool init(sdl_t *sdl, config_t *s)
{
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
        SDL_Log("SLD n'est pas initialiser! %s\n", SDL_GetError());
        return false;
    }
    sdl->window = SDL_CreateWindow("Chip 8 experimentation",
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    s->Win_width * s->scale_factor,
                                    s->Win_height * s->scale_factor,
                                    0);
    if (!sdl->window) {
        SDL_Log("SDL window de peut pas etre cree %s\n", SDL_GetError());
        return false;
    }
    sdl->rend = SDL_CreateRenderer(sdl->window, -1, SDL_RENDERER_ACCELERATED);
    if (!sdl->rend) {
        SDL_Log("SDL renderer n'a pas etais cree %s\n", SDL_GetError());
        return false;
    }
    return true;
}

bool init_chip8(chip8_t *chip8)
{
    chip8->state = RUNNING;
    return true;
}