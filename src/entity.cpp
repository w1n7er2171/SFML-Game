#include <iostream>

#include "Entity.h"
#include "Game.h"

Asteroid::Asteroid()
{
	asteroidSpeed = 3.f;

	asteroidSprite = nullptr;
}

void Asteroid::SetAsteroidSprite(Sprite& asteroidSprite)
{
	this->asteroidSprite = &asteroidSprite;
	this->asteroidSprite->scale(4, 4);
	this->asteroidSprite->setOrigin(16.F, 16.F);
	this->asteroidSprite->move(10.f, 10.f);
}





Bullet::Bullet()
{
	bulletSpeed = 5.f;
	RectangleShape bullet;
	bullet.setFillColor(Color::White);
	bullet.setSize(Vector2f(10.f, 10.f));

	ShootingDelayClock.getElapsedTime();
	//std::cout << ShootingDelay;
}

void Bullet::Shoot()
{
	this->mousePosition = Mouse::getPosition();

	//std::cout << ShootingDelay;

	if (Mouse::isButtonPressed(Mouse::Left))
	{
		Bullet *bullet = new Bullet();
		this->bullets.push_back(&bullet);
		std::cout << "shoot!\n";
	}
}

Bullet::~Bullet()
{

}





Player::Player()
{
	movementSpeed = 2.f;

	deltaTime = deltaTimeClock.restart().asSeconds();

	playerSprite = nullptr;

	//FloatRect& nextPosition = this->playerSprite->getPosition() + movementSpeed;
}

void Player::SetSprite(Sprite& playerSprite)
{
	this->playerSprite = &playerSprite;
	this->playerSprite->scale(2, 2);
	this->playerSprite->setOrigin(16.F, 16.F);
	this->playerSprite->move(Vector2f(100.f, 100.f));
}

void Player::Move()
{
	Vector2f playerPosition = playerSprite->getPosition();
	//std::cout << playerPosition.x << ", " << playerPosition.y << std::endl;
	//std::cout << mousePosition.x << ", " << mousePosition.y << std::endl;
	//Rotation();

	//for (auto )

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		playerSprite->setPosition(playerPosition.x - movementSpeed, playerPosition.y);
		if (playerSprite->getPosition().x < 20)
			playerSprite->setPosition(20, playerPosition.y);
	}

	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		playerSprite->setPosition(playerPosition.x + movementSpeed, playerPosition.y);
		if (playerSprite->getPosition().x > 1260)
			playerSprite->setPosition(1260, playerPosition.y);
	}

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		playerSprite->setPosition(playerPosition.x, playerPosition.y - movementSpeed);
		if (playerSprite->getPosition().y < 20)
			playerSprite->setPosition(playerPosition.x, 20);
	}

	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		playerSprite->setPosition(playerPosition.x, playerPosition.y + movementSpeed);
		if (playerSprite->getPosition().y > 700)
			playerSprite->setPosition(playerPosition.x, 700);
	}
}

/*void Player::Rotation()
{
	Vector2f playerPos = playerSprite->getPosition();

	this->mousePosition = Mouse::getPosition();

	float angle = acos(-1)*(((playerPos.x + playerPos.y) * (mousePosition.x + mousePosition.y)) / (sqrtf(powf(playerPos.x, 2)+ powf(playerPos.y, 2)) * (sqrtf(powf(mousePosition.x, 2) + powf(mousePosition.y, 2)))));

	//float angle = atan2f(mousePosition.y - playerPos.y, mousePosition.x - playerPos.x);
	
	float angleDegrees = angle * (180/3.1415926);

	playerSprite->setRotation(angleDegrees);
	std::cout << angleDegrees << " ," << playerPos.x << " " << playerPos.y << std::endl;
}*/

// https://www.sfml-dev.org/tutorials/2.5/graphics-transform.php
// https://en.sfml-dev.org/forums/index.php?topic=544.0
