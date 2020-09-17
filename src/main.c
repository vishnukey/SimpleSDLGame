#include <core.h>
#include <lib.h>

SDL_Renderer* renderer;
const int WINDOW_HEIGHT = 627;
const int WINDOW_WIDTH = 660;

int main(void)
{
        struct window_ctx ctx = init("My Simple Game", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT);
        renderer = ctx.ren;
        SDL_Renderer* ren = renderer;


        start(); 

        bool close = FALSE;
        while (!close) {
                input in = handle_events(&close); 

                //update
                update(in, &close);

                // Render
                SDL_RenderClear(ren);
                
                draw();
                
                SDL_RenderPresent(ren);
                SDL_Delay(1000 / 60); // 60 FPS
        }

        finished();
        cleanup(ctx);
        return EXIT_SUCCESS;
}




