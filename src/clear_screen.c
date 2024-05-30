#include "../include/chip8.h"

void clear_screen(sdl_t *sdl)
{
    SDL_SetRenderDrawColor(sdl->rend, 0, 0, 0, 255);
    SDL_RenderClear(sdl->rend);
}