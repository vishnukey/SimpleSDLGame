#ifndef CONTEXT__HPP__
#define CONTEXT__HPP__

#include <SDL2/SDL.h>

#include <Colour.hpp>

namespace Graphics{
        class Context{
                public:
                        const static Colour CLEAR_COLOUR;

                private:
                        SDL_Window*   _window = nullptr;
                        SDL_Renderer* _renderer = nullptr;
                        inline void setColour(Colour const& col);
                public:
                        Context() = default;
                        Context(Context const& other) = delete;
                        Context(Context&& other);
                        Context& operator=(Context const& other) = delete;
                        Context& operator=(Context&& other);
                        Context(SDL_Window* win, SDL_Renderer* ren);

                        ~Context();

                        void clear();
                        void display();

                        void rect(float x, float y, float w, float h, Colour col = Colour::MAGENTA);
                        void line(float x1, float y1, float x2, float y2, Colour col = Colour::MAGENTA); 
        };
};
#endif
