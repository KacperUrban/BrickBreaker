#include "Player.h"
#include <iostream>
Player::Player()
{
	this->initPlayer();
}

void Player::initPlayer()
{
	if (!this->tPlayer.loadFromFile("texture/paddle.png"))
	{
		std::cout << "Error load from file" << std::endl;
	}
	this->sPlayer.setTexture(this->tPlayer);
	this->playerVector = sf::Vector2f(300.0f, 750.0f);
	this->sPlayer.setOrigin(sf::Vector2f(150 / 2, 10 / 2));
	this->sPlayer.setPosition(this->playerVector);
}

void Player::update(sf::Event event, sf::RenderWindow* window)
{
	this->mousePosition = sf::Mouse::getPosition(*window);
	sf::Vector2f mPosition2f = sf::Vector2f(this->mousePosition);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (mPosition2f.x > this->sPlayer.getOrigin().x + 0.0f && mPosition2f.x < 600 - this->sPlayer.getOrigin().x)
		{
			this->playerVector = sf::Vector2f(mPosition2f.x, 750.0f);
			this->sPlayer.setPosition(this->playerVector);
		}
	}
}

sf::Sprite Player::returnPlayer()
{
	return this->sPlayer;
}

void Player::render(sf::RenderWindow* window)
{
	window->draw(this->sPlayer);
}
