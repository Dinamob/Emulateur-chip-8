#include "../include/chip8.h"

void update_screen(sdl_t *sdl)
{
    SDL_RenderPresent(sdl->rend);
}