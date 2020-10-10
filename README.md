# A simple Game made in SDL

This is the C11 version of the project. The design is build around
abstracting away the calls to SDL and the game loop to focus
soley on writing game logic. `App.c` contains the main logic for the game.
Abstraction barriers are created through the use of header files and separate
source code files. `Lib.c` provides the implementation of drawing primitives
that are accessible in `App.c` through the `Lib.h` header. `Lib.c` communicates
with SDL and the game loop through `Core.h` and `Core.c`, while `App.c` does not
see these functions. To have a working game, it suffices to provide implementations
for `start`, `update`, `draw`, and `finished` in `App.c`
