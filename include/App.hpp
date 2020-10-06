#ifndef APP__HPP__
#define APP__HPP__

#include <SDL2/SDL.h>
#include <string>

#include <Context.hpp>

template<typename Game>
class App{
        public:
                static constexpr float TARGET_FRAME_TIME = 1.f / 60.f;
                static constexpr float SECONDS_TO_MILLIS = 1000;
        private:
                bool close = false;
                Graphics::Context ctx;
                Game game{};

                void handle_events()
                {
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

                }

                void tick(float elapsedTime)
                {
                        handle_events(); 
                        
                        //update
                        game.update(elapsedTime);

                        // Render
                        ctx.clear();

                        game.draw(ctx);

                        ctx.display();
                }
        public:
                App(std::string title, int x, int y, int width, int height)
                {
                        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
                                fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
                        }

                        SDL_Window* win = SDL_CreateWindow(title.c_str(), x, y, width, height, SDL_WINDOW_SHOWN);
                        if (win == NULL) {
                                fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
                        }

                        SDL_Renderer* ren = SDL_CreateRenderer(win, -1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
                        if (ren == NULL) {
                                fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
                                if (win != NULL) {
                                        SDL_DestroyWindow(win);
                                }
                                SDL_Quit();
                        }
                        ctx = {win, ren}; // takes ownership
                }

                ~App()
                {
                        SDL_Quit();
                }

                void start()
                {
                        game.setup(ctx);
                        while(!close){
                                tick(TARGET_FRAME_TIME);
                                SDL_Delay(TARGET_FRAME_TIME * SECONDS_TO_MILLIS); // 60 FPS
                        }
                }

                void stop()
                {
                        close = true;
                }
};

#endif
