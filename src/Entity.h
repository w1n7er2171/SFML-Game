#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

class Entity
{
private:



protected:



private:
	Entity();
	virtual ~Entity();

	//Functions
	virtual void update(const float& deltaTime) = 0;
	virtual void render(sf::RenderTarget& target) = 0;
};

