#include <iostream>

#include "Game.h"

int main()
{
	//Init game engine
	Game game;

	Player player;

	game.textureLoad();

	player.SetSprite(game.getSprite());

	//Game loop
	while (game.running())
	{

		game.updateDeltaTime();

		//Update
		game.update();

		player.Move();
		//Render

		game.render();

	}

	//Game closes

	return 0;
}