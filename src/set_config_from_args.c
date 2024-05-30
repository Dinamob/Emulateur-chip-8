#include "../include/chip8.h"

bool set_config_from_args(config_t *s, int ac, char **av)
{
    *s = (config_t){.Win_width = WIDTH,
                    .Win_height = HEIGHT,
                    .frontground_color = 0xFFF00FF0,
                    .background_color = 0x00000000,
                    .scale_factor = SCALE
                    };
    for (int i = 0; i < ac; i++) {
        (void)av[i];
    }
    return true;
}