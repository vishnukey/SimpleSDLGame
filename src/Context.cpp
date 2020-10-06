#include <Context.hpp>
namespace Graphics{
        Context::Context(SDL_Window* win, SDL_Renderer* ren) : _window(win), _renderer(ren) 
        { 

        }

        Context::~Context()
        {
                SDL_DestroyRenderer(_renderer);
                SDL_DestroyWindow(_window);
        }

        void Context::clear()
        {
                SDL_RenderClear(_renderer);
        }

        void Context::display()
        {
                SDL_RenderPresent(_renderer);
        }

        void Context::rect(int x, int y, int w, int h, Colour col)
        {
                SDL_Rect rect{x, y, w, h};

        }

        void Context::line(int x1, int y1, int x2, int y2, Colour col)
        {

        }
};
