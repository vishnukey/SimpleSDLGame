#ifndef EVENTS__HPP__
#define EVENTS__HPP__

#include <array>
#include <cstring>

struct Event{
        struct Key{
                enum class State : uint8_t { 
                        EMPTY = 0, 
                        PRESSED = 1 << 0 , 
                        RELEASED = 1 << 1, 
                        HELD = 1 << 2, 
                };
                State A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,Y,Z,
                      UP, DOWN, LEFT, RIGHT,
                      ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO;
        };

        union {
                Key table;
                std::array<Key::State, sizeof(Key) * sizeof(Key::State)> data;
        } key;

        Event()
        {
                memset(key.data.data(), (int)Key::State::EMPTY, key.data.size());
        }
};
#endif
