#ifndef APP__HPP__
#define APP__HPP__

#include <SDL2/SDL.h>
#include <string>

#include <Context.hpp>

class App{
        public:
                static constexpr int FPS = 1000 / 60;
        private:
                bool close = false;
                Graphics::Context ctx;
        protected:
        public:

        private:
                void tick();
        protected:
                virtual void setup()  = 0;
                virtual void update(float elapsedTime) = 0;
                virtual void draw(Graphics::Context& ctx)   = 0;
        public:
                App(std::string title, int x, int y, int width, int height);
                virtual ~App();

                void start();
                void stop();
};

#endif
