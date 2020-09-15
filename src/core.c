#include <stdio.h>
#include <stdlib.h>

#include <core.h>
#include <lib.h>

struct window_ctx init(const char* name, int x, int y, int w, int h)
{
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_Window *win = SDL_CreateWindow(name, x, y, w, h, SDL_WINDOW_SHOWN);
	if (win == NULL) {
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_Renderer *ren = SDL_CreateRenderer(win, -1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == NULL) {
		fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
		if (win != NULL) {
			SDL_DestroyWindow(win);
		}
		SDL_Quit();
		exit(EXIT_FAILURE);
	}

        struct window_ctx ctx = {
                .ren = ren,
                .win = win,
        };

        SDL_SetRenderDrawColor(renderer, BG_COL.r, BG_COL.g, BG_COL.b, BG_COL.a); // black


        return ctx;
}

void cleanup(struct window_ctx ctx)
{
        SDL_DestroyRenderer(ctx.ren);
	SDL_DestroyWindow(ctx.win);
	SDL_Quit();
}

void handle_events(uint8_t* close)
{
        SDL_Event event; 
          
        // Events mangement 
        while (SDL_PollEvent(&event)) { 
            switch (event.type) { 
                    case SDL_QUIT: 
                        // handling of close button 
                        *close = 1; 
                        break; 
          
                    case SDL_KEYDOWN: 
                        // keyboard API for key pressed 
                        switch (event.key.keysym.scancode) { 
                                case SDL_SCANCODE_W: 
                                case SDL_SCANCODE_UP: 
                                    //dest.y -= speed / 30; 
                                    break; 
                                case SDL_SCANCODE_A: 
                                case SDL_SCANCODE_LEFT: 
                                    //dest.x -= speed / 30; 
                                    break; 
                                case SDL_SCANCODE_S: 
                                case SDL_SCANCODE_DOWN: 
                                    //dest.y += speed / 30; 
                                    break; 
                                case SDL_SCANCODE_D: 
                                case SDL_SCANCODE_RIGHT: 
                                    //dest.x += speed / 30; 
                                    break;
                                default:
                                    break;
                        }
                    default:
                        break;
            } 
        }
}
