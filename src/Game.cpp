#include <Game.hpp>

#include <iostream>

Game::Game() : App{"Simple Game", 100, 100, 620, 387} 
{ 

}

void Game::setup()
{

}

void Game::update(float elapsedTime)
{
        if (x > 100) x = 0;
        x += speed * elapsedTime;;
}

void Game::draw(Graphics::Context& ctx)
{
        ctx.rect(x, y, w, h, Graphics::Colour::GREEN);
}

