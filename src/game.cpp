#include <iostream>

#include "Game.h"



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

void Game::textureLoad()
{
	sf::Texture texture;
	if (!texture.loadFromFile("res/Spaceship.png"))
	{
		std::cout << "Texture Spaceship.png failed to load";
	}

	sf::Sprite sprite;
	sprite.setTexture(texture);

	this->window->draw(sprite);
}

void Game::pollEvents()
{
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
	

}

void Game::render()
{

	this->window->clear();

	//Draw new frame

	this->window->display();

}
