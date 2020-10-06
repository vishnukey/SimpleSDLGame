#include <App.hpp>

#include <stdio.h>

App::App(std::string title, int x, int y, int width, int height)
{
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
                fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
                //return EXIT_FAILURE;
        }

        SDL_Window* win = SDL_CreateWindow(title.c_str(), x, y, width, height, SDL_WINDOW_SHOWN);
        if (win == NULL) {
                fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
                //return EXIT_FAILURE;
        }

        SDL_Renderer* ren = SDL_CreateRenderer(win, -1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (ren == NULL) {
                fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
                if (win != NULL) {
                        SDL_DestroyWindow(win);
                }
                SDL_Quit();
                //return EXIT_FAILURE;
        }
        ctx = {win, ren};
}

App::~App()
{
        //SDL_DestroyRenderer(ren);
        //SDL_DestroyWindow(win);
        SDL_Quit();
}

void App::start()
{
        tick();
}

void App::stop()
{
        close = true;
}
        
void App::tick()
{
        setup();

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
                update(FPS);

                // Render
                ctx.clear();

                draw(ctx);

                ctx.display();
                SDL_Delay(FPS); // 60 FPS
        }

}



