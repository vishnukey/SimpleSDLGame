#include <iostream>

#include <Engine.hpp>
#include <Game.hpp>

int main(void)
{
	//Engine<Game> app{"Simple Game", 100, 100, 620, 387};
        Engine<Game> game{"Simple Game", 100, 100, 620, 687};

        game.start();

	return EXIT_SUCCESS;
}
