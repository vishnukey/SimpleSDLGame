#include <iostream>

#include <Engine.hpp>
#include <Game.hpp>

int main(void)
{
	Engine<Game> app{"Simple Game", 100, 100, 620, 387};

        app.start();

	return EXIT_SUCCESS;
}
