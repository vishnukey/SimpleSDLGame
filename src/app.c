#include <lib.h>

typedef struct {
        int x;
        const int w, h, y;
        const colour col;
        int speed;
} player;

typedef struct {
        int y;
        colour col;
        const int w, h, x;
        int speed;
} enemy;

typedef struct {
        const int x, length;
        int speed;
        int y;
} shot;

//int x, y, w, h;

player p = {
        .x = 100,
        .y = 550,
        .w = 20,
        .h = 50,
        .col = (colour)0x661111FF,
        .speed = 5,
};

shot test = {
        .x = 100,
        .y = 400,
        .length = 100,
        .speed = -20,
};
const colour SHOT_COL = (colour)0x662266FF;

void drawShot(shot* sht);

void start()
{
       // w = 50;
       // h = 50;
       // x = 10;
       // y = 10;
}

void update(input in)
{
        p.x += in.horizontal * p.speed;
        test.y += test.speed;
        //y += in.vertical * speed;
        if (in.fire) printf("fired!\n");
}

void draw()
{
        rect(p.x, p.y, p.w, p.h, p.col);
        drawShot(&test);

}

void drawShot(shot* sht)
{
        line(sht->x - 1, sht->y, sht->x - 1, sht->y + sht->length, SHOT_COL);
        line(sht->x    , sht->y, sht->x    , sht->y + sht->length, SHOT_COL);
        line(sht->x + 1, sht->y, sht->x + 1, sht->y + sht->length, SHOT_COL);
}
