#include "../include/chip8.h"

void cleanup(sdl_t *sdl)
{
    SDL_DestroyRenderer(sdl->rend);
    SDL_DestroyWindow(sdl->window);
    SDL_Quit();
}