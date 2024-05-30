#ifndef CHIP8_H_
    #define CHIP8_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <SDL2/SDL.h>

#define WIDTH 50
#define HEIGHT 60
#define SCALE 10

typedef struct color_s {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
} color_t;

typedef struct sdl_s {
    SDL_Window *window;
    SDL_Renderer *rend;
} sdl_t;

typedef struct config_s {
    uint32_t Win_width;
    uint32_t Win_height;
    uint32_t frontground_color;
    uint32_t background_color;
    uint32_t scale_factor;
} config_t;

typedef enum {
    QUIT,
    RUNNING,
    PAUSED
} etat_t;


typedef struct chip8_s {
    etat_t state;
} chip8_t;

bool init(sdl_t *sdl, config_t *s);
void handle_input(chip8_t *chip8);
bool init_chip8(chip8_t *chip8);
bool set_config_from_args(config_t *s, int ac, char **av);
void cleanup(sdl_t *sdl);
void clear_screen(sdl_t *sdl);
void update_screen(sdl_t *sdl);

#endif
