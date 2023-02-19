#include <iostream>

#include "Entity.h"
#include "Game.h"

Entity::Entity()
{
	this->asteroidSpeed = 100.F;
}

Entity::~Entity()
{
}

Player::Player()
{
	movementSpeed = 0.1f;
	playerSprite = nullptr;
}
//
//Player::Player(Sprite& playerSprite, float movementSpeed)
//{
//	this->playerSprite = &playerSprite;
//	this->movementSpeed = movementSpeed;
//}

void Player::SetSpeed(float movementSpeed)
{
	this->movementSpeed = movementSpeed;
}

void Player::SetSprite(Sprite& playerSprite)
{
	this->playerSprite = &playerSprite;
	this->playerSprite->setOrigin(16.F, 16.F);
}

void Player::Move()
{
	Vector2f playerPosition = playerSprite->getPosition();
	Vector2f playerGlobalPosition = Vector2f(playerSprite->getTransform().transformPoint(playerPosition.x, playerPosition.y));
	std::cout << playerGlobalPosition.x << ", " << playerGlobalPosition.y << std::endl;

	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		
		playerSprite->rotate(-0.1F); //setPosition(playerPosition.x - movementSpeed, playerPosition.y);
	}
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		playerSprite->rotate(0.1F); //setPosition(playerPosition.x + movementSpeed, playerPosition.y);
		//playerSprite->setPosition(playerPosition.x + movementSpeed, playerPosition.y);
	}

	if ((Keyboard::isKeyPressed(Keyboard::Up)))
	{
		playerSprite->setPosition(cos(playerSprite->getRotation() * 3.14159265 / 180) * 3, sin(playerSprite->getRotation() * 3.14159265 / 180) * -3); //playerPosition.x , playerPosition.y - movementSpeed);
	}

	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		playerSprite->setPosition(cos(playerSprite->getRotation() * 3.14159265 / 180) * -3, sin(playerSprite->getRotation() * 3.14159265 / 180) * 3); //playerPosition.x, playerPosition.y + movementSpeed);
	}
}

// https://www.sfml-dev.org/tutorials/2.5/graphics-transform.php
// https://en.sfml-dev.org/forums/index.php?topic=544.0