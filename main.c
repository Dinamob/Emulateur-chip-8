#include "include/chip8.h"

int main(int ac, char **av)
{
    sdl_t sdl;
    config_t s;
    chip8_t chip8;

    if (!set_config_from_args(&s, ac, av))
        exit(EXIT_FAILURE);
    if (!init(&sdl, &s))
        exit(EXIT_FAILURE);
    if (!init_chip8(&chip8))
        exit(EXIT_FAILURE);
    while (chip8.state != QUIT) {
        clear_screen(&sdl);
        SDL_Delay(16);
        handle_input(&chip8);
        update_screen(&sdl);
    }
    cleanup(&sdl);
    exit(EXIT_SUCCESS);
}
