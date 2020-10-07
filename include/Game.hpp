#ifndef GAME__HPP__
#define GAME__HPP__

#include <Context.hpp>
#include <Events.hpp>

class Game{
        private:
                const float y = 10.f, h = 50.f, w = 50.f, speed = 100.f;
                float x = 50.f;
        public:
                void setup(Graphics::Context& ctx);
                bool update(float elapsedTime, Event const& input);
                void draw(Graphics::Context& ctx);
}; 

#endif
