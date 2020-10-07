#ifndef GAME__HPP__
#define GAME__HPP__

#include <Context.hpp>
#include <Events.hpp>

class Player{
        private:
                float _x, _y;
                float _width, _height;
                float _speed;
                Graphics::Colour col;
        public:
                enum Dir{ LEFT = -1, NONE = 0, RIGHT = 1 };
                Player(
                                float x, float y, 
                                float w = 30, float h = 45, 
                                float s = 200, Graphics::Colour c = {0x00, 0xff, 0x00}
                        ) : _x(x), _y(y), _width(w), _height(h), _speed(s), col(c) 
                {

                }
                
                void update(float elapsedTime, Dir inputDir, bool shoot=false)
                {
                        _x += _speed * elapsedTime * (int)inputDir;
                }

                void draw(Graphics::Context& ctx)
                {
                        ctx.rect(_x, _y, _width, _height, col);
                }
};

class Game{
        private:
                const float y = 10.f, h = 50.f, w = 50.f, speed = 100.f;
                float x = 50.f;
                Player player{0, 0};
        public:
                Game() = default;
                void setup(Graphics::Context& ctx);
                bool update(float elapsedTime, Event const& input);
                void draw(Graphics::Context& ctx);
}; 

#endif
