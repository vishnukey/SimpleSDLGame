#include <iostream>

#include <App.hpp>
#include <Game.hpp>

int main(void)
{
	App<Game> app{"Simple Game", 100, 100, 620, 387};

        app.start();


       
	return EXIT_SUCCESS;
}
