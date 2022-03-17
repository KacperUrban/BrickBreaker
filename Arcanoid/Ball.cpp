#include "Ball.h"

Ball::Ball()
{
	this->initBall();
	this->mouseClick = false;
	this->counter = 0;
	this->end = false;
}

void Ball::initBall()
{
	this->ball.setRadius(10.0f);
	this->ball.setPosition(300.0f, 728.0f);
	this->ball.setFillColor(sf::Color::Red);
	this->mPosX = 0.0f;
	this->mPosY = 0.0f;
	this->ballMoveVector = sf::Vector2f(this->mPosX, this->mPosY);
	this->strTab = new std::string[2];
	this->strTab[0] = "right";
	this->strTab[1] = "up";
}
void Ball::checkBound()
{
	sf::Vector2f ballVector = this->ball.getPosition();
	this->bPosX = ballVector.x;
	this->bPosY = ballVector.y;
	if (this->bPosX < 0.f)
	{
		this->ballMoveVector.x = this->ballMoveVector.x - (this->ballMoveVector.x * 2);
		this->strTab[0] = "right";
		
	}
	if (this->bPosX > 590.f)
	{
		this->ballMoveVector.x = this->ballMoveVector.x - (this->ballMoveVector.x * 2);
		this->strTab[0] = "left";

	}
	if (this->bPosY < 0.f)
	{
		this->ballMoveVector.y = this->ballMoveVector.y - (ballMoveVector.y * 2);
		this->strTab[1] = "down";
	}
	if (this->bPosY > 800.f)
	{
		counter++;
		if (this->counter == 3)
		{
			this->end = true;
		}
		this->ballMoveVector.x = 0.f;
		this->ballMoveVector.y = 0.f;
		this->ball.setPosition(300.0f, 728.0f);
		this->mouseClick = false;
	}

}

void Ball::collisionWithPlayer(sf::Sprite player)
{
	if (player.getGlobalBounds().intersects(this->ball.getGlobalBounds()))
	{
		this->ballMoveVector.y = this->ballMoveVector.y - (ballMoveVector.y * 2);
		this->strTab[1] = "up";
	}
}

sf::CircleShape Ball::returnBall()
{
	return this->ball;
}

sf::Vector2f Ball::returnBallMoveVector()
{
	return this->ballMoveVector;
}

void Ball::setBallMoveVector(sf::Vector2f vector)
{
	this->ballMoveVector = vector;
}

void Ball::update(sf::Sprite player)
{
	if (this->mouseClick == false)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			this->ballMoveVector.x = 6.0f;
			this->ballMoveVector.y = -14.0f;
			this->mouseClick = true;
		}
		else
		{
			this->ball.setPosition(player.getPosition().x, 728.0f);
		}
	}
	this->checkBound();
	this->ball.move(this->ballMoveVector);
}

void Ball::render(sf::RenderTarget* target)
{
	target->draw(this->ball);
}
