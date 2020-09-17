#include <lib.h>
#include <list.h>
#include <config.h>

typedef struct {
        int x;
        const int w, h, y;
        colour col;
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


player p = {
        .x = PLAYER_START_X,
        .y = PLAYER_Y,
        .w = PLAYER_WIDTH,
        .h = PLAYER_HEIGHT,
        .col = {},
        .speed = PLAYER_START_SPEED,
};

list* shotList = NULL;
list* enemyList = NULL;

void drawShot(shot* sht);
void initShot(shot* sht);

void drawEnemy(enemy* enemy);
void initEnemy(enemy* enemy);

void start()
{
        printf("Starting game\n");
        p.col = PLAYER_START_COLOUR;
        shotList = list_new();
        enemyList = list_new();

        /// TESTING
        struct node* ePtr = list_push(enemyList, sizeof(enemy));
        enemy* testE = (enemy*)ePtr->data;
        testE->h = 55;
        testE->w = 25;
        testE->speed = 1;
        testE->x = 50;
        testE->y = -testE->h;
        testE->col = (colour)(int)0xFF0000FF;
}

void update(input in, bool* close)
{
        p.x += in.horizontal * p.speed;

        if (in.fire) {
                struct node* nodePtr = list_push(shotList, sizeof(shot));
                shot* newShot = (shot*)nodePtr->data;
                initShot(newShot);
        }

        for (list* it = shotList->next; it != NULL; it = it->next)
        {
                shot* s = (shot*)it->data;
                s->y += s->speed;
                if (s->y < 0){
                        it = remove_node(it);
                        if (it == NULL) break;
                }

                for (list* jt = enemyList->next; jt != NULL; jt = jt->next)
                {
                        enemy* e = (enemy*)jt->data; 
                        if( // Check if the shot, s, is colliding with the enemy, e
                                s->x+1 > e->x && 
                                s->x-1 < e->x + e->w &&
                                s->y < e->y + e->h && 
                                s->y + s->length > e->y
                        ){
                                jt = remove_node(jt);
                                if (jt == NULL) break;
                        }
                }
        }

        for (list* it = enemyList->next; it != NULL; it = it->next)
        {
                enemy* e = (enemy*)it->data;
                e->y += e->speed;

                if (e->y >= WINDOW_HEIGHT) *close = TRUE;
        }
}

void draw()
{
        for (list* it = enemyList->next; it != NULL; it = it->next)
        {
                drawEnemy((enemy*)it->data);
        }

        for (list* it = shotList->next; it != NULL; it = it->next)
        {
                drawShot((shot*)it->data);
        }

        rect(p.x, p.y, p.w, p.h, p.col);
}

void finished()
{
        list_free(shotList);
        list_free(enemyList);
        printf("All done\n");
}

void drawShot(shot* sht)
{
        line(sht->x - 1, sht->y, sht->x - 1, sht->y + sht->length, SHOT_COL);
        line(sht->x    , sht->y, sht->x    , sht->y + sht->length, SHOT_COL);
        line(sht->x + 1, sht->y, sht->x + 1, sht->y + sht->length, SHOT_COL);
}

void initShot(shot* sht)
{
        sht->x = p.x + (p.w / 2);
        sht->y = SHOT_START_Y;
        sht->length = SHOT_LENGTH;
        sht->speed = SHOT_SPEED;
}

void drawEnemy(enemy* enemy)
{
        rect(enemy->x, enemy->y, enemy->w, enemy->h, enemy->col);
}

void initEnemy(enemy* enemy)
{

}

