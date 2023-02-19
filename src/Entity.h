#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Game.h"

class Entity
{
private:



protected:

	float movementSpeed;

public:
	Entity();
	virtual ~Entity();

	//Functions
	static void move(const float& deltaTime,const float x, const float y);

	virtual void update(const float& deltaTime) = 0;
	virtual void render(sf::RenderTarget& target) = 0;
};

