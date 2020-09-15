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

input handle_events(uint8_t* close)
{
        SDL_Event event; 
        input in = {
                .horizontal = 0,
                .vertical = 0,
                .fire = FALSE,
        };
          
        // Events mangement 
        while (SDL_PollEvent(&event)) { 
            switch (event.type) { 
                    case SDL_QUIT: 
                        // handling of close button 
                        *close = TRUE; 
                        break; 
          
                    case SDL_KEYDOWN: 
                        // keyboard API for key pressed 
                        if( event.key.keysym.scancode == SDL_SCANCODE_W 
                        || event.key.keysym.scancode == SDL_SCANCODE_UP){ 
                            in.vertical -= 1; 
                        }
                        if (event.key.keysym.scancode == SDL_SCANCODE_A
                        || event.key.keysym.scancode == SDL_SCANCODE_LEFT){
                            in.horizontal -= 1; 
                        }
                        if (event.key.keysym.scancode == SDL_SCANCODE_S
                        || event.key.keysym.scancode == SDL_SCANCODE_DOWN){
                            in.vertical += 1;
                        }
                        if (event.key.keysym.scancode == SDL_SCANCODE_D 
                        || event.key.keysym.scancode == SDL_SCANCODE_RIGHT){
                            in.horizontal += 1;
                        }
                        if (event.key.keysym.scancode == SDL_SCANCODE_SPACE && !event.key.repeat){
                                in.fire = TRUE;
                        }
                        break;
                    default:
                        break;
            } 
        }

        return in;
}
