#ifndef CONTEXT__HPP__
#define CONTEXT__HPP__

#include <concepts>

#include <SDL2/SDL.h>

#include <Colour.hpp>
#include <Events.hpp>

namespace Graphics{
        class Context{
                public:
                        const static Colour CLEAR_COLOUR;
                private:
                        SDL_Window*   _window = nullptr;
                        SDL_Renderer* _renderer = nullptr;
                        inline void setColour(Colour const& col);
                        int _width, _height;
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
                        Context(SDL_Window* win, SDL_Renderer* ren, int w, int h);

                        // Cleanup the window and render context
                        ~Context();

                        inline int width(){ return _width; }
                        inline int height(){ return _height; }

                        void clear();
                        void display();

                        void rect(float x, float y, float w, float h, Colour col = Colour::MAGENTA);
                        void line(float x1, float y1, float x2, float y2, Colour col = Colour::MAGENTA); 
        };

        template <typename R>
        concept Runner = requires(R r, Context& c, float e, Event const& i) {
                requires std::default_initializable<R>;
                { r.update(e, i) } -> std::same_as<bool>;
                { r.draw(c)      } -> std::same_as<void>;
        };
        template <typename S>
        concept CanSetup = requires(S s, Context& c){
                { s.setup(c) } -> std::same_as<void>;
        };
        template <typename C>
        concept CanClose = requires(C c, Context& ctx){
                { c.close(ctx) } -> std::same_as<void>;
        };
};

#endif
