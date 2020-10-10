# A simple Game made in SDL

This is the C++20 version of the game. The idea
is to have A class (in this case Game) to handle the main
logic of the game while an `Engine` class manages SDL behind 
the scenes. `Engine` is templated in such a way so that the
`Game` class may be provided at compile time and needs
only suitable `draw` and `update` methods to work. 
Using new C++ concepts ensures with nice error messags
that `Game` compiles with the interface, and also allows
for `setup` and `close` methods to optionally be used if
they exist. `Game` communicates with SDL through the 
`Graphics::Context` class, which handles drawing and
manages the `SDL_Renderer` and `SDL_Window` pointers. 
