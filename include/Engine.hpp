#ifndef ENGINE__HPP__
#define ENGINE__HPP__

#include <iostream>

#include <SDL2/SDL.h>

#include <Context.hpp>
#include <Events.hpp>

template<Graphics::Runner Game>
class Engine{
        public:
                static constexpr float TARGET_FRAME_TIME = 1.f / 60.f;
                static constexpr float SECONDS_TO_MILLIS = 1000;
        private:
                bool close = false;
                Graphics::Context ctx;

                Game game{};
                Event input;

                void update_input(Event::Key::State& key, Event::Key::State event)
                {
                        switch(key){
                                case Event::Key::State::EMPTY:
                                        key = event;
                                        break;
                                case Event::Key::State::PRESSED:
                                        switch(event){
                                                case Event::Key::State::EMPTY:
                                                case Event::Key::State::PRESSED:
                                                        key = Event::Key::State::HELD;
                                                        break;
                                                case Event::Key::State::RELEASED:
                                                        key = Event::Key::State::RELEASED;
                                                        break;
                                                case Event::Key::State::HELD:
                                                        break;
                                        }
                                        break;
                                case Event::Key::State::RELEASED:
                                        switch(event){
                                                case Event::Key::State::EMPTY:
                                                        key = Event::Key::State::EMPTY;
                                                        break;
                                                case Event::Key::State::PRESSED:
                                                        key = Event::Key::State::PRESSED;
                                                        break;
                                                default:
                                                        break;
                                        }
                                        break;
                                case Event::Key::State::HELD:
                                        switch(event){
                                                case Event::Key::State::RELEASED:
                                                        key = Event::Key::State::RELEASED;
                                                        break;
                                                default:
                                                        break;
                                        }
                                        break;
                        }
                }

                void handle_events()
                {
                        SDL_Event event; 
                        // Events mangement 
                        while (SDL_PollEvent(&event)) { 
                            switch (event.type) { 
                                    case SDL_QUIT: 
                                        // handling of close button
                                        close = true; 
                                        break; 
                          
                                    case SDL_KEYDOWN: 
                                        // keyboard API for key pressed 
                                        switch (event.key.keysym.scancode) { 
                                                case SDL_SCANCODE_W:
                                                        update_input(input.key.table.W, Event::Key::State::PRESSED);
                                                        break;
                                                case SDL_SCANCODE_UP: 
                                                        update_input(input.key.table.UP, Event::Key::State::PRESSED);
                                                        break; 
                                                case SDL_SCANCODE_A:
                                                        update_input(input.key.table.A, Event::Key::State::PRESSED);
                                                        break;
                                                case SDL_SCANCODE_LEFT: 
                                                        update_input(input.key.table.LEFT, Event::Key::State::PRESSED);
                                                        break; 
                                                case SDL_SCANCODE_S: 
                                                        update_input(input.key.table.S, Event::Key::State::PRESSED);
                                                        break;
                                                case SDL_SCANCODE_DOWN: 
                                                        update_input(input.key.table.DOWN, Event::Key::State::PRESSED);
                                                        break; 
                                                case SDL_SCANCODE_D: 
                                                        update_input(input.key.table.D, Event::Key::State::PRESSED);
                                                        break;
                                                case SDL_SCANCODE_RIGHT: 
                                                        update_input(input.key.table.RIGHT, Event::Key::State::PRESSED);
                                                        break;
                                                default:
                                                        break;
                                        }
                                        break;
                                case SDL_KEYUP:
                                        switch (event.key.keysym.scancode) { 
                                                case SDL_SCANCODE_W:
                                                        update_input(input.key.table.W, Event::Key::State::RELEASED);
                                                        break;
                                                case SDL_SCANCODE_UP: 
                                                        update_input(input.key.table.UP, Event::Key::State::RELEASED);
                                                        break; 
                                                case SDL_SCANCODE_A:
                                                        update_input(input.key.table.A, Event::Key::State::RELEASED);
                                                        break;
                                                case SDL_SCANCODE_LEFT: 
                                                        update_input(input.key.table.LEFT, Event::Key::State::RELEASED);
                                                        break; 
                                                case SDL_SCANCODE_S: 
                                                        update_input(input.key.table.S, Event::Key::State::RELEASED);
                                                        break;
                                                case SDL_SCANCODE_DOWN: 
                                                        update_input(input.key.table.DOWN, Event::Key::State::RELEASED);
                                                        break; 
                                                case SDL_SCANCODE_D: 
                                                        update_input(input.key.table.D, Event::Key::State::RELEASED);
                                                        break;
                                                case SDL_SCANCODE_RIGHT: 
                                                        update_input(input.key.table.RIGHT, Event::Key::State::RELEASED);
                                                        break;
                                                default:
                                                        break;
                                        }
                                        break;
                                    default:
                                        break;
                            } 
                        }

                }

                void tick(float elapsedTime)
                {
                        handle_events(); 
                       
                        //update
                        close |= !game.update(elapsedTime, input);

                        for (uint8_t i = 0; i < input.key.data.size(); i++)
                                update_input((Event::Key::State&)(input.key.data[i]), Event::Key::State::EMPTY);

                        // Render
                        ctx.clear();

                        game.draw(ctx);

                        ctx.display();
                }
        public:
                Engine(std::string title, int x, int y, int width, int height)
                {
                        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
                                fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
                                throw "Failed to init SDL";
                        }

                        SDL_Window* win = SDL_CreateWindow(title.c_str(), x, y, width, height, SDL_WINDOW_SHOWN);
                        if (win == NULL) {
                                fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
                                throw "Failed to create Window";
                        }

                        SDL_Renderer* ren = SDL_CreateRenderer(win, -1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
                        if (ren == NULL) {
                                fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
                                if (win != NULL) {
                                        SDL_DestroyWindow(win);
                                }
                                SDL_Quit();
                                throw "Failed to create renderer";
                        }
                        ctx = {win, ren, width, height}; // takes ownership
                }

                ~Engine()
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
                        game.close(ctx);
                }

                void stop()
                {
                        close = true;
                }
};

#endif
