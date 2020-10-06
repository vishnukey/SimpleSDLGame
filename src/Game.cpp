#include <Game.hpp>

#include <iostream>

Game::Game()
{ 

}

void Game::setup(Graphics::Context& ctx)
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

