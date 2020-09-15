#ifndef LIB__H__
#define LIB__H__

#include <SDL2/SDL.h>

#define TRUE 1
#define FALSE 0

typedef union {
        int data;
        struct{ // be carefule with endianness
                uint8_t a;
                uint8_t b;
                uint8_t g;
                uint8_t r;
        };
} colour; // RGBA
typedef uint8_t bool;

typedef struct {
        char horizontal;
        char vertical;
        bool fire;
} input;

extern const colour BG_COL;

void start(void);
void update(input in);
void draw(void);

void rect(int x, int y, int w, int h, colour col);
void line(int x1, int y1, int x2, int y2, colour col);

#endif
