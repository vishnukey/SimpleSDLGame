#include <iostream>

#include <Game.hpp>

void Game::setup(Graphics::Context& ctx)
{
        width = ctx.width();
        height = ctx.height();
        player = {ctx.width() / 2.f, ctx.height() - 70.f};

        enemies.emplace_back(20);
}

bool Game::update(float elapsedTime, Event const& input)
{
        //Player::Dir dir = Player::NONE;
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
       
        float dx = 0;
        if (input.key.table.A == Event::Key::State::HELD) dx = -elapsedTime;
        if (input.key.table.D == Event::Key::State::HELD) dx = elapsedTime;

        player.move(dx);
        if (input.key.table.SPACE == Event::Key::State::PRESSED){
                shots.push_back(player.shoot());
        }

        for (auto it = begin(shots); it != end(shots); /* increment in loop */) {
                auto& s = *it;
                if(s.update(elapsedTime)){
                        it = shots.erase(it);
                }else ++it;
        }
        
        for (auto& e : enemies)
                if(e.update(elapsedTime, height)) return false; // end the game when an enemy says so


        // collision detection
        for (auto it = begin(enemies); it != end(enemies); /* increment in loop */){
                auto& e = *it;
                bool hit = false;
                for (auto jt = begin(shots); jt != end(shots); /* increment in loop */){
                        auto& s = *jt;
                        if (s.collide(e)){ // on collision, destroy both enemy and shot
                                jt = shots.erase(jt);
                                it = enemies.erase(it);
                                hit = true;
                        }else
                                ++jt;
                }
                if (hit) hit = false;
                else ++it;
        }
        

        return true;
}

void Game::draw(Graphics::Context& ctx)
{
        for (auto& e : enemies) e.draw(ctx);
        for (auto& s : shots) s.draw(ctx);
        player.draw(ctx);
}


