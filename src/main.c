#include <core.h>
#include <lib.h>

SDL_Renderer* renderer;

int main(void)
{
        struct window_ctx ctx = init("My Simple Game", 100, 100, 660, 627);
        renderer = ctx.ren;
        SDL_Renderer* ren = renderer;


        start(); 

        bool close = FALSE;
        while (!close) {
                handle_events(&close); 

                //update
                update();

                // Render
                SDL_RenderClear(ren);
                
                draw(ren);
                
                SDL_RenderPresent(ren);
                SDL_Delay(1000 / 60); // 60 FPS
        }

        cleanup(ctx);
        return EXIT_SUCCESS;
}




