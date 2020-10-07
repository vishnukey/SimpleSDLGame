#include <iostream>

#include <Game.hpp>

void Game::setup(Graphics::Context& ctx)
{

}

bool Game::update(float elapsedTime, Event const& input)
{
        static unsigned long long int frameCount = 0;

        frameCount++;

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
        if (x > 100) x = 0;
        x += speed * elapsedTime;

        if (frameCount > 200) {
                std::cout << "Finsihed!" << std::endl;
                return false;
        }

        return true;
}

void Game::draw(Graphics::Context& ctx)
{
        ctx.rect(x, y, w, h, Graphics::Colour::GREEN);
}

