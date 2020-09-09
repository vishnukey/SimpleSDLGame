#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	SDL_Window *win = SDL_CreateWindow("Simple Game", 100, 100, 620, 387, SDL_WINDOW_SHOWN);
	if (win == NULL) {
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	SDL_Renderer *ren = SDL_CreateRenderer(win, -1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == NULL) {
		fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
		if (win != NULL) {
			SDL_DestroyWindow(win);
		}
		SDL_Quit();
		return EXIT_FAILURE;
	}

        SDL_Rect myRect = {
                .w = 50,
                .h = 50,
                .x = 10,
                .y = 10,
        };

        uint8_t close = 0;
        while (!close) {
                SDL_Event event; 
          
                // Events mangement 
                while (SDL_PollEvent(&event)) { 
                    switch (event.type) { 
                            case SDL_QUIT: 
                                // handling of close button 
                                close = 1; 
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

                //update
                myRect.x += 1;
                myRect.x %= 100;

                // Render
                SDL_RenderClear(ren);

                SDL_SetRenderDrawColor(ren, 0, 255, 0, 255); // green
                SDL_RenderFillRect(ren, &myRect);
                SDL_SetRenderDrawColor(ren, 0, 0, 0, 255); // black

                SDL_RenderPresent(ren);
                SDL_Delay(1000 / 60); // 60 FPS
        }

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return EXIT_SUCCESS;
}
