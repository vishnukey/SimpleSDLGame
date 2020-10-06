#ifndef GAME__HPP__
#define GAME__HPP__

//#include <App.hpp>

#include <Context.hpp>

class Game{
        private:
                const float y = 10.f, h = 50.f, w = 50.f, speed = 100.f;
                float x = 50.f;
        public:
                void setup(Graphics::Context& ctx);
                void update(float elapsedTime);
                void draw(Graphics::Context& ctx);
                Game();
}; 

#endif
