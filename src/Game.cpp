#include <Game.hpp>

Game::Game() : App{"Simple Game", 100, 100, 620, 387} 
{ 

}

void Game::setup()
{
        rect.w = 50;
        rect.h = 50;
        rect.x = 10;
        rect.y = 10;
}

void Game::update(float elapsedTime)
{
        rect.x += 1;
        rect.x %= 100;
}

void Game::draw(Graphics::Context& ctx)
{
        //SDL_SetRenderDrawColor(ren, 0, 255, 0, 255); // green
        //SDL_RenderFillRect(ren, &rect);
        ctx.rect(rect.x, rect.y, rect.w, rect.h);
        //SDL_SetRenderDrawColor(ren, 0, 0, 0, 255); // black
}

