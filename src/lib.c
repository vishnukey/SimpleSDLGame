#include <lib.h>
#include <core.h>

const colour BG_COL = (colour)0x000000FF; // black, full alpha

void rect(int x, int y, int w, int h, colour col)
{
        SDL_Rect rect = {
                .x = x,
                .y = y,
                .w = w,
                .h = h,
        };
        SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, col.a); // green
        SDL_RenderFillRect(renderer, &rect);
        SDL_SetRenderDrawColor(renderer, BG_COL.r, BG_COL.g, BG_COL.b, BG_COL.a); // black

}

void line(int x1, int y1, int x2, int y2, colour col)
{
        SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, col.a);
        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
        SDL_SetRenderDrawColor(renderer, BG_COL.r, BG_COL.g, BG_COL.b, BG_COL.a);
}

