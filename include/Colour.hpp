#ifndef COLOUR__HPP__
#define COLOUR__HPP__

#include <cstdint>

namespace Graphics{
        struct Colour{
                private:
                        uint8_t _a;
                        uint8_t _b;
                        uint8_t _g;
                        uint8_t _r;
                public:
                        inline Colour(int r, int g, int b, int a = 255) : _a(a), _b(b), _g(g), _r(r) {}//_data(r, g, b, a) { }
                        inline Colour(int col) : _a((col >> 24) & 0xFF), _b((col >> 16) & 0xff), _g((col >> 8) & 0xFF), _r(col & 0xFF) { }
                        inline Colour(uint32_t col) : Colour(static_cast<int>(col)) { }

                        inline uint32_t r() const { return _r; }
                        inline uint32_t g() const { return _g; }
                        inline uint32_t b() const { return _b; }
                        inline uint32_t a() const { return _a; }

                        static const Colour BLACK;
                        static const Colour WHITE;
                        static const Colour RED;
                        static const Colour GREEN;
                        static const Colour BLUE;
                        static const Colour YELLOW;
                        static const Colour MAGENTA;
                        static const Colour CYAN;
        };

};
#endif
