#include <lib.h>

int x, y, w, h;

void start()
{
        w = 50;
        h = 50;
        x = 10;
        y = 10;
}

void update()
{
        x += 1;
        x %= 100;
}

void draw()
{
        rect(x, y, w, h, (colour)0x00FF00FF);
}
