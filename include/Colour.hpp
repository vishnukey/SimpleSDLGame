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
                                constexpr __color_data(uint32_t d): raw(d) { }
                                constexpr __color_data(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a):
                                        r(_r), g(_g), b(_b), a(_a) { }
                        } _data;
                public:
                        constexpr explicit Colour(int c) : _data(static_cast<uint32_t>(c)) { }

                        constexpr explicit Colour(uint32_t c) : _data(c) { }

                        constexpr Colour(int r, int g, int b, int a = 255) : _data(r, g, b, a) { }

                        constexpr uint32_t r()    const { return _data.r; }
                        constexpr uint32_t g()    const { return _data.g; }
                        constexpr uint32_t b()    const { return _data.b; }
                        constexpr uint32_t a()    const { return _data.a; }
                        constexpr uint32_t data() const { return _data.raw; }

                        const static Colour BLACK;
                        const static Colour WHITE;
                        const static Colour RED;
                        const static Colour GREEN;
                        const static Colour BLUE;
                        const static Colour YELLOW;
                        const static Colour MAGENTA;
                        const static Colour CYAN;
        };

        const Colour Colour::BLACK     = {0  , 0  , 0  };
        const Colour Colour::WHITE     = {255, 255, 255};
        const Colour Colour::RED       = {255, 0  , 0  };
        const Colour Colour::GREEN     = {0  , 255, 0  };
        const Colour Colour::BLUE      = {0  , 0  , 255};
        const Colour Colour::YELLOW    = {255, 255, 0  };
        const Colour Colour::MAGENTA   = {255, 0  , 255};
        const Colour Colour::CYAN      = {0  , 255, 255};
};
#endif
