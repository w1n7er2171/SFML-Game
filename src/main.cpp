#include <iostream>

#include "Game.h"

int main()
{
	//Init game engine
	Game game;



	//Game loop
	while (game.running())
	{

		//Load texture
		game.textureLoad();

		//Update
		game.update();

		//Render

		game.render();

	}

	//Game closes

	return 0;
}