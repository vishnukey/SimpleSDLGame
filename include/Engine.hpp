#ifndef ENGINE__HPP__
#define ENGINE__HPP__

#include <iostream>

#include <SDL2/SDL.h>

#include <Context.hpp>
#include <Events.hpp>

#define CHECK_KEY_F(source, target, type) \
        case SDL_SCANCODE_ ## source:{\
                update_input(input.keys.target, Event::Key::State::type); \
                break;}
#define CHECK_KEY(key, type) CHECK_KEY_F(key, key, type)
#define PRESS(key) CHECK_KEY(key, PRESSED)
#define RELEASE(key) CHECK_KEY(key, RELEASED)

#define PRESS_F(sdlkey, eventkey) CHECK_KEY_F(sdlkey, eventkey, PRESSED)
#define RELEASE_F(sdlkey, eventkey) CHECK_KEY_F(sdlkey, eventkey, RELEASED)

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
                                                PRESS(A);
                                                PRESS(B);
                                                PRESS(C);
                                                PRESS(D);
                                                PRESS(E);
                                                PRESS(F);
                                                PRESS(G);
                                                PRESS(H);
                                                PRESS(I);
                                                PRESS(J);
                                                PRESS(K);
                                                PRESS(L);
                                                PRESS(M);
                                                PRESS(N);
                                                PRESS(O);
                                                PRESS(P);
                                                PRESS(Q);
                                                PRESS(T);
                                                PRESS(S);
                                                PRESS(R);
                                                PRESS(U);
                                                PRESS(V);
                                                PRESS(W);
                                                PRESS(X);
                                                PRESS(Y);
                                                PRESS(Z);

                                                PRESS(UP);
                                                PRESS(DOWN);
                                                PRESS(LEFT);
                                                PRESS(RIGHT);
                                                PRESS(SPACE);

                                                PRESS_F(0, ZERO);
                                                PRESS_F(1, ONE);
                                                PRESS_F(2, TWO);
                                                PRESS_F(3, THREE);
                                                PRESS_F(4, FOUR);
                                                PRESS_F(5, FIVE);
                                                PRESS_F(6, SIX);
                                                PRESS_F(7, SEVEN);
                                                PRESS_F(8, EIGHT);
                                                PRESS_F(9, NINE);
                                                default:
                                                        break;
                                        }
                                        break;
                                    case SDL_KEYUP:
                                        switch (event.key.keysym.scancode) { 
                                                RELEASE(A);
                                                RELEASE(B);
                                                RELEASE(C);
                                                RELEASE(D);
                                                RELEASE(E);
                                                RELEASE(F);
                                                RELEASE(G);
                                                RELEASE(H);
                                                RELEASE(I);
                                                RELEASE(J);
                                                RELEASE(K);
                                                RELEASE(L);
                                                RELEASE(M);
                                                RELEASE(N);
                                                RELEASE(O);
                                                RELEASE(P);
                                                RELEASE(Q);
                                                RELEASE(R);
                                                RELEASE(S);
                                                RELEASE(T);
                                                RELEASE(U);
                                                RELEASE(V);
                                                RELEASE(W);
                                                RELEASE(X);
                                                RELEASE(Y);
                                                RELEASE(Z);

                                                RELEASE(UP);
                                                RELEASE(DOWN);
                                                RELEASE(LEFT);
                                                RELEASE(RIGHT);
                                                RELEASE(SPACE);

                                                RELEASE_F(0, ZERO);
                                                RELEASE_F(1, ONE);
                                                RELEASE_F(2, TWO);
                                                RELEASE_F(3, THREE);
                                                RELEASE_F(4, FOUR);
                                                RELEASE_F(5, FIVE);
                                                RELEASE_F(6, SIX);
                                                RELEASE_F(7, SEVEN);
                                                RELEASE_F(8, EIGHT);
                                                RELEASE_F(9, NINE);
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

                        for (uint8_t i = 0; i < sizeof(Event::Key); i++)
                                update_input(reinterpret_cast<Event::Key::State*>(&input.keys)[i], Event::Key::State::EMPTY);

                        // Render
                        ctx.clear();

                        game.draw(ctx);

                        ctx.display();
                }

                template <typename>
                inline void doSetup(){ }
                template <Graphics::CanSetup>
                inline void doSetup(){ game.setup(ctx); }

                template <typename>
                inline void doClose(){ }
                template <Graphics::CanClose>
                inline void doClose(){ game.close(ctx); }
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
                        doSetup<Game>();
                        while(!close){
                                tick(TARGET_FRAME_TIME);
                                SDL_Delay(TARGET_FRAME_TIME * SECONDS_TO_MILLIS); // 60 FPS
                        }
                        doClose<Game>();
                }

                void stop()
                {
                        close = true;
                }
};

#endif
