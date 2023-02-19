#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
using namespace sf;

#include "Game.h"

class Entity
{
private:



protected:

	float asteroidSpeed;

public:
	Entity();
	virtual ~Entity();

	//Functions
	
};



class Player
{
private:
	Sprite* playerSprite;
	float movementSpeed;
public:
	Player();
	/*Player(Sprite& playerSprite, float movementSpeed);*/

	void SetSpeed(float movementSpeed);
	void SetSprite(Sprite& playerSprite);

	void Move();
};