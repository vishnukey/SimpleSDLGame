#ifndef COLOUR__HPP__
#define COLOUR__HPP__

#include <cstdint>

namespace Graphics{
        struct Colour{
                private:
                        union __color_data{
                                uint32_t raw;
                                struct {
                                        uint8_t a;
                                        uint8_t b;
                                        uint8_t g;
                                        uint8_t r;
                                };
                                inline __color_data(uint32_t d): raw(d) { }
                                inline __color_data(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a):
                                        a(_a), b(_b), g(_g), r(_r) { }
                        } _data;
                public:
                        inline explicit Colour(int c) : _data(static_cast<uint32_t>(c)) { }

                        inline explicit Colour(uint32_t c) : _data(c) { }

                        inline Colour(int r, int g, int b, int a = 255) : _data(r, g, b, a) { }

                        inline uint32_t r()    const { return _data.r; }
                        inline uint32_t g()    const { return _data.g; }
                        inline uint32_t b()    const { return _data.b; }
                        inline uint32_t a()    const { return _data.a; }
                        inline uint32_t data() const { return _data.raw; }

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
