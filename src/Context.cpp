#include <Context.hpp>

#include <iostream>

namespace Graphics{
        const Colour Context::CLEAR_COLOUR = Colour::BLACK;

        Context::Context(SDL_Window* win, SDL_Renderer* ren) : _window(win), _renderer(ren) 
        { 
                
        }

        Context::Context(Context&& other)
        {
                _window = std::move(other._window);
                _renderer = std::move(other._renderer);

                other._window = nullptr;
                other._renderer = nullptr;
        }

        Context& Context::operator=(Context&& other)
        {
                _window = std::move(other._window);
                _renderer = std::move(other._renderer);

                other._window = nullptr;
                other._renderer = nullptr;
                
                return *this;
        }

        Context::~Context()
        {
                if (_renderer) SDL_DestroyRenderer(_renderer);
                if (_window) SDL_DestroyWindow(_window);
        }

        void Context::clear()
        {
                setColour(CLEAR_COLOUR);
                SDL_RenderClear(_renderer);
        }

        void Context::display()
        {
                SDL_RenderPresent(_renderer);
        }

        void Context::rect(float x, float y, float w, float h, Colour col)
        {
                SDL_Rect rect{(int)x, (int)y, (int)w, (int)h};

                setColour(col);
                SDL_RenderFillRect(_renderer, &rect);
                setColour(CLEAR_COLOUR); 
        }

        void Context::line(float x1, float y1, float x2, float y2, Colour col)
        {
                setColour(col);
                SDL_RenderDrawLine(_renderer, (int)x1, (int)y1, (int)x2, (int)y2);
                setColour(CLEAR_COLOUR);
        }

        inline void Context::setColour(Colour const& col)
        {
                SDL_SetRenderDrawColor(_renderer, col.r(), col.g(), col.b(), col.a());
        }
};
