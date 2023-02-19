#include <iostream>

#include "Game.h"

int main()
{
	//Init game engine
	Game game;

	game.textureLoad();

	//Game loop
	while (game.running())
	{

		game.updateDeltaTime();

		//Update
		game.update();

		//Render

		game.render();

	}

	//Game closes

	return 0;
}