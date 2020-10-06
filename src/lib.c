#include <lib.h>
#include <core.h>

const colour BG_COL = (colour)0x000000FF; // black, full alpha

void rect(float x, float y, float w, float h, colour col)
{
        SDL_Rect rect = {
                .x = (int)x,
                .y = (int)y,
                .w = (int)w,
                .h = (int)h,
        };
        SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, col.a); // green
        SDL_RenderFillRect(renderer, &rect);
        SDL_SetRenderDrawColor(renderer, BG_COL.r, BG_COL.g, BG_COL.b, BG_COL.a); // black

}

void line(float x1, float y1, float x2, float y2, colour col)
{
        SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, col.a);
        SDL_RenderDrawLine(renderer, (int)x1, (int)y1, (int)x2, (int)y2);
        SDL_SetRenderDrawColor(renderer, BG_COL.r, BG_COL.g, BG_COL.b, BG_COL.a);
}

