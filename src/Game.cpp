#include <iostream>

#include <Game.hpp>

void Game::setup(Graphics::Context& ctx)
{
        player = {ctx.width() / 2.f, ctx.height() - 70.f};
}

bool Game::update(float elapsedTime, Event const& input)
{
        Player::Dir dir = Player::NONE;
        switch(input.key.table.W){
                case Event::Key::State::PRESSED:
                        std::cout << "W key pressed" << std::endl;
                case Event::Key::State::HELD:
                        std::cout << "W key held" << std::endl;
                        break;
                case Event::Key::State::RELEASED:
                        std::cout << "W key released" << std::endl;
                default:
                        break;
        }
        
        if (input.key.table.A == Event::Key::State::HELD) dir = Player::LEFT;
        if (input.key.table.D == Event::Key::State::HELD) dir = Player::RIGHT;

        player.update(elapsedTime, dir);

        if (x > 100) x = 0;
        x += speed * elapsedTime;

        return true;
}

void Game::draw(Graphics::Context& ctx)
{
        ctx.rect(x, y, w, h, Graphics::Colour::GREEN);
        player.draw(ctx);
}

void Game::close(Graphics::Context& ctx)
{

}

