#ifndef GAME__HPP__
#define GAME__HPP__

#include <Context.hpp>
#include <Events.hpp>

#include <vector>

class Enemy{
        private:
                float _x, _y;
                float _width, _height;
                float _speed;
                Graphics::Colour col;
        public:   
                Enemy(
                        float x, float s = 50, 
                        float w = 30, float h = 45, 
                        float y = 0, Graphics::Colour c = Graphics::Colour::RED
                ) : _x(x), _y(y), _width(w), _height(h), _speed(s), col(c) 
                {

                }

                bool update(float elapsedTime, float bottom)
                {
                        _y += _speed * elapsedTime;
                        if (_y > bottom) return true;
                        else return false;
                }

                void draw(Graphics::Context& ctx)
                {
                        ctx.rect(_x, _y, _width, _height, col);
                }

                float x() const { return _x; }
                float y() const { return _y; }
                float width() const { return _width; }
                float height() const { return _height; }
};

class Shot{
        float _x, _y, _speed, _len;
        Graphics::Colour _col;
        public:
                Shot(float x, float y, float s = 500, float len = 70, Graphics::Colour col = Graphics::Colour::MAGENTA) :
                        _x(x), _y(y), _speed(s), _len(len), _col(col)
                {

                }

                bool update(float elapsedTime)
                {
                       _y -= _speed * elapsedTime;
                       if (_y <= -_len) return true;
                       else return false;
                }

                void draw(Graphics::Context& ctx)
                {
                        ctx.line(_x - 1, _y, _x - 1, _y + _len, _col);
                        ctx.line(_x, _y, _x, _y + _len, _col); 
                        ctx.line(_x + 1, _y, _x + 1, _y + _len, _col);
                }

                bool collide(Enemy& e)
                {
                       return false; 
                }
};

class Player{
        private:
                float _x, _y;
                float _width, _height;
                float _speed;
                Graphics::Colour col;
        public:
                //enum Dir{ LEFT = -1, NONE = 0, RIGHT = 1 };
                Player(
                                float x, float y, 
                                float w = 30, float h = 45, 
                                float s = 200, Graphics::Colour c = {0x00, 0xff, 0x00}
                        ) : _x(x), _y(y), _width(w), _height(h), _speed(s), col(c) 
                {

                }
                
                void move(float dx){
                        _x += dx * _speed;
                }

                Shot shoot(){
                        return {_x + _width / 2, _y - _height/2};
                }

                void draw(Graphics::Context& ctx)
                {
                        ctx.rect(_x, _y, _width, _height, col);
                }
};

class Game{
        private:
                //const float y = 10.f, h = 50.f, w = 50.f, speed = 100.f;
                //float x = 50.f;
                Player player{0, 0};
                std::vector<Shot> shots;
                std::vector<Enemy> enemies;
                float width, height;
        public:
                Game()  = default;
                ~Game() = default;
                void setup(Graphics::Context& ctx);
                bool update(float elapsedTime, Event const& input);
                void draw(Graphics::Context& ctx);
}; 

#endif
