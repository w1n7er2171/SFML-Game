#include <iostream>

#include "Game.h"

int main()
{
	//Init game engine
	Game game;

	Player player;
	Asteroid asteroid;
	Bullet bullet;

	game.textureLoad();

	player.SetSprite(game.getPlayerSprite());
	asteroid.SetAsteroidSprite(game.getAsteroidSprite());
	

	//Collision

	

	//Game loop
	while (game.running())
	{

		bullet.Shoot();

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