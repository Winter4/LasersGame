#include <SFML/Graphics.hpp>
#include "Headers/Game.h"
#include <time.h>

int main()
{
	srand(time(0));

	Game game;
	game.run();
}

// PASSED