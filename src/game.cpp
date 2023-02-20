#include <iostream>

#include "Game.h"
#include "Entity.h"

//Private func
void Game::initVar()
{
	this->window = nullptr;
}

void Game::initWindow()
{

	this->videoMode.width = 1280;
	this->videoMode.height = 720;

	this->window = new sf::RenderWindow(this->videoMode, "Game");

	this->window->setFramerateLimit(120);

}

Game::Game()
{

	this->initVar();
	this->initWindow();

}

Game::~Game()
{

	delete this->window;

}

//Accessors

const bool Game::running() const
{
	return this->window->isOpen();
}

//Functions

void Game::updateDeltaTime()
{

	this->deltaTime = this->deltaTimeClock.restart().asSeconds();
	//std::cout << deltaTime << std::endl;

}

void Game::textureLoad()
{
	playerTexture.loadFromFile("res/Spaceship.png");
	asteroidTexture.loadFromFile("res/Asteroid.png");
	if (!playerTexture.loadFromFile("res/Spaceship.png")) {std::cout << "Texture Spaceship.png failed to load";}
	if (!asteroidTexture.loadFromFile("res/Asteroid.png")) {std::cout << "Texture Asteroid.png failed to load";}

	player.setTexture(playerTexture);
	asteroid.setTexture(asteroidTexture);
}

void Game::pollEvents()
{
	bool fullScreenActive = false;

	//Event polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::update()
{
	this->pollEvents();
	sf::Vector2f movement;

}

void Game::render()
{

	this->window->clear();
	
	//Draw new frame
	window->draw(player);
	window->draw(asteroid);

	this->window->display();

}

Sprite& Game::getPlayerSprite()
{
	return this->player;
}

Sprite& Game::getAsteroidSprite()
{
	return this->asteroid;
}
