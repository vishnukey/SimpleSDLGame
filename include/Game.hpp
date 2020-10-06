#ifndef GAME__HPP__
#define GAME__HPP__

#include <App.hpp>

class Game: public App {
        private:
                const float y = 10.f, h = 50.f, w = 50.f, speed = 100.f;
                float x = 50.f;
        protected:
                void setup()  override;
                void update(float elapsedTime) override;
                void draw(Graphics::Context& ctx)   override;
        public:
                Game();
}; 

#endif
