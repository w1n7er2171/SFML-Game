#pragma once

#include <ctime>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

//Game engine

class Game
{
private:

	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Private func
	void initVar();
	void initWindow();

public:

	//Constructors & Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;

	//Functions
	void pollEvents();
	void update();
	void render();

};

