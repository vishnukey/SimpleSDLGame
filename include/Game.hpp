#ifndef GAME__HPP__
#define GAME__HPP__

#include <App.hpp>

class Game: public App {
        private:
                SDL_Rect rect;
        protected:
                void setup()  override;
                void update(float elapsedTime) override;
                void draw(Graphics::Context& ctx)   override;
        public:
                Game();
}; 

#endif
