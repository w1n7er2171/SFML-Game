#pragma once

#include <ctime>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

#include "Entity.h"

//Game engine

class Game
{
private:

	sf::Texture playerTexture;
	sf::Sprite player;
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	sf::Clock deltaTimeClock;
	float deltaTime;


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
	void updateDeltaTime();
	void textureLoad();
	void pollEvents();
	void update();
	void render();

	Sprite& getSprite();

};

