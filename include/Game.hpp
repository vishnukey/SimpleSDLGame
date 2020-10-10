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
                        float x, float s = 10, 
                        float w = 25, float h = 55, 
                        float y = -55, Graphics::Colour c = Graphics::Colour::RED
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
                Shot(
                                float x, float y, 
                                float s = 1000, float len = 100, 
                                Graphics::Colour col = {0x66, 0x22, 0x66}
                ):
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
                        return (// Check if this shot is colliding with the enemy, e
                                _x+1 > e.x() && 
                                _x-1 < e.x() + e.width() &&
                                _y < e.y() + e.height() && 
                                _y + _len > e.y()
                        );
                }
};

class Player{
        private:
                float _x, _y;
                float _width, _height;
                float _speed;
                Graphics::Colour col;
        public:
                Player(
                                float x, float y, 
                                float w = 20, float h = 50, 
                                float s = 200, Graphics::Colour c = {0x66, 0x11, 0x11}
                        ) : _x(x), _y(y), _width(w), _height(h), _speed(s), col(c) 
                {

                }
                
                void move(float dx){
                        _x += dx * _speed;
                }

                Shot shoot(){
                        
                        return {_x + _width / 2, _y - _height};
                }

                void draw(Graphics::Context& ctx)
                {
                        ctx.rect(_x, _y, _width, _height, col);
                }
};

class Game{
        private:
                Player player{100, 550};
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
