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
extern const int WINDOW_HEIGHT;
extern const int WINDOW_WIDTH;

void start(void);
void update(input in, bool* close);
void draw(void);
void finished(void);

void rect(float x, float y, float w, float h, colour col);
void line(float x1, float y1, float x2, float y2, colour col);

#endif
