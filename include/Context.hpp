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
                        Context() = default; // intialize with nullptr

                        // make sure we can't copy - only one thing can
                        // own _window and _renderer
                        Context(Context const& other) = delete;
                        Context& operator=(Context const& other) = delete;

                        // but we can move it, but we need to
                        // do it manually so we don't accidentally
                        // destroy things
                        Context(Context&& other);
                        Context& operator=(Context&& other);

                        // So we can take ownership of resources
                        // We can't acquire them ourselves because
                        // We don't have the information to construct them
                        Context(SDL_Window* win, SDL_Renderer* ren);

                        // Cleanup the window and render context
                        ~Context();

                        void clear();
                        void display();

                        void rect(float x, float y, float w, float h, Colour col = Colour::MAGENTA);
                        void line(float x1, float y1, float x2, float y2, Colour col = Colour::MAGENTA); 
        };
};
#endif
