#include <lib.h>
#include <list.h>

typedef struct {
        int x;
        const int w, h, y;
        const colour col;
        int speed;
} player;

typedef struct {
        int y;
        colour col;
        int w, h, x;
        int speed;
} enemy;

typedef struct {
        int x, length;
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

list* shotList = NULL;

void drawShot(shot* sht);

void start()
{
        printf("Starting game\n");
       // w = 50;
       // h = 50;
       // x = 10;
       // y = 10;
       shotList = list_new();
}

void update(input in)
{
        p.x += in.horizontal * p.speed;
        test.y += test.speed;
        //y += in.vertical * speed;
        if (in.fire) {
                struct node* nodePtr = list_push(shotList, sizeof(shot));
                shot* newShot = (shot*)nodePtr->data;
                newShot->x = p.x + (p.w / 2);
                newShot->y = p.y - p.h;
                newShot->length = 100;
                newShot->speed = -20;
        }

        for (list* it = shotList->next; it != NULL; it = it->next)
        {
                shot* s = (shot*)it->data;
                s->y += s->speed;
                if (s->y < 0){
                        it = remove_node(it);
                        if (it == NULL) break;
                }
        }
}

void draw()
{
        drawShot(&test);
        for (list* it = shotList->next; it != NULL; it = it->next)
        {
                drawShot((shot*)it->data);
        }

        rect(p.x, p.y, p.w, p.h, p.col);
}

void finished()
{
        list_free(shotList);
        printf("All done\n");
}

void drawShot(shot* sht)
{
        line(sht->x - 1, sht->y, sht->x - 1, sht->y + sht->length, SHOT_COL);
        line(sht->x    , sht->y, sht->x    , sht->y + sht->length, SHOT_COL);
        line(sht->x + 1, sht->y, sht->x + 1, sht->y + sht->length, SHOT_COL);
}
