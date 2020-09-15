#ifndef CORE__H__
#define CORE__H__

#include <SDL2/SDL.h>

extern SDL_Renderer* renderer;

struct window_ctx {
        SDL_Renderer* ren;
        SDL_Window* win;
};

struct window_ctx init(const char*, int, int, int, int);
void cleanup(struct window_ctx);

void handle_events(uint8_t*);

#endif
