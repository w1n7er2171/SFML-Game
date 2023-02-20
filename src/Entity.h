#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
using namespace sf;

#include "Game.h"

class Asteroid
{
private:
	Sprite* asteroidSprite;
	float asteroidSpeed;

public:
	Asteroid();

	void SetAsteroidSprite(Sprite& asteroidSprite);
	
};

class Bullet
{
private:
	float bulletSpeed;

	sf::Clock ShootingDelayClock;
	float ShootingDelay;
	std::vector<Bullet> bullets{};

	Vector2i mousePosition;

public:
	Bullet();
	void Shoot();
	~Bullet();
};

class Player
{
private:
	sf::Clock deltaTimeClock;
	float deltaTime;
	Sprite* playerSprite;
	float movementSpeed;

public:
	Player();

	Vector2f velocity;
	void SetSprite(Sprite& playerSprite);

	void Move();
	//void Rotation();
};