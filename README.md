# A simple Game made in SDL

The idea for the game is shown is ASCII art below

```
##################
#                #
#          %%    #
#          %*    #
#         * | *  #
#    %%          #
#    %%          #
#    %%          #
#                #
#                #
#                #
#                #
#    |           #
#                #
#    p           #
#                #
##################
```

The repository implements two different version of the game, 
one written in c11 and the other written in C++20. No libraries
outside of SDL2 or libc/libc++ is used. The c version of the code
is in branch `processing_like`, as the main logic file, 
`app.c` is meant to emulate the style of processing. 
The branch `cpp` contains the C++ version of the program, 
though the design paralles the C version and attempts to be
just as friendly. Both versions are designed so as to have
the game logic code be removed and another game easily built
on top instead.

