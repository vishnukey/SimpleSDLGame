#ifndef CONTEXT__HPP__
#define CONTEXT__HPP__

#include <SDL2/SDL.h>

#include <Colour.hpp>

namespace Graphics{
        class Context{
                public:
                        constexpr static Colour CLEAR_COLOUR = {0,0,0}; // black

                private:
                        SDL_Window*   _window = nullptr;
                        SDL_Renderer* _renderer = nullptr;
                public:
                        Context() = default;
                        Context(Context& other) = delete;
                        Context(SDL_Window* win, SDL_Renderer* ren);

                        ~Context();

                        void clear();
                        void display();

                        void rect(int x, int y, int w, int h, Colour col = Colour::MAGENTA);
                        void line(int x1, int y1, int x2, int y2, Colour col = Colour::MAGENTA); 
        };
};
#endif
