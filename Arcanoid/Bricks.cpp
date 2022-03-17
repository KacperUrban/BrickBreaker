#include "Bricks.h"
#include <iostream>

Bricks::Bricks()
{
	this->initBrick();
	this->points = 0;
}

void Bricks::initBrick()
{
	sf::RectangleShape tmp;
	this->brickVectorSize = sf::Vector2f(50.0f, 20.0f);
	float x = 60.0;
	float y = 10.0f; 
	int j = 0, counterColor = 0;
	sf::Color color[4];
	color[0] = sf::Color::Green;
	color[1] = sf::Color::Blue;
	color[2] = sf::Color::Yellow;
	color[3] = sf::Color::Cyan;
	for (int i = 0; i < 100; i++)
	{
		if (j == 10)
		{
			y += 35.0f;
			x = 65.0;
			j = 0;
			counterColor++;
		}
		if ((j != 0) && (j != 9) && (i > 9) && (j != 4) && (j != 5))
		{
			tmp.setSize(this->brickVectorSize);
			tmp.setFillColor(color[counterColor]);
			tmp.setOutlineThickness(4.0f);
			tmp.setOutlineColor(sf::Color::Black);
			tmp.setPosition(j * x, y);
			this->bricks.push_back(tmp);
		}
		j++;
		if (counterColor == 4)
		{
			counterColor = 0;
		}
	}
}

int Bricks::returnPoints()
{
	return this->points;
}

sf::Vector2f Bricks::collisionWithBall(sf::CircleShape ball, sf::Vector2f ballMoveVector, std::string* strTab)
{
	for (int i = 0; i < bricks.size(); i++)
	{
		if (ball.getGlobalBounds().intersects(this->bricks[i].getGlobalBounds()))
		{
			sf::RectangleShape tmp = this->bricks[i];
			if (strTab[1] == "up")
			{
				if ((strTab[0] == "left") && (ball.getPosition().x > tmp.getPosition().x + 50.f) && ((ball.getPosition().y < tmp.getPosition().y + 20.0) && (ball.getPosition().y > tmp.getPosition().y)))
				{
					strTab[0] = "right";
					ballMoveVector.x = ballMoveVector.x - (ballMoveVector.x * 2);
				}
				else if ((strTab[0] == "right") && (ball.getPosition().x < tmp.getPosition().x) && ((ball.getPosition().y < tmp.getPosition().y + 2.0) && (ball.getPosition().y > tmp.getPosition().y)))
				{
					strTab[0] = "left";
					ballMoveVector.x = ballMoveVector.x - (ballMoveVector.x * 2);
				}
				else
				{
					strTab[1] = "down";
					ballMoveVector.y = ballMoveVector.y - (ballMoveVector.y * 2);
				}
			}
			else
			{
				if ((strTab[0] == "left") && (ball.getPosition().x >= tmp.getPosition().x + 48.0f) && ((ball.getPosition().y < tmp.getPosition().y + 20.0) && (ball.getPosition().y > tmp.getPosition().y)))
				{
					strTab[0] = "right";
					ballMoveVector.x = ballMoveVector.x - (ballMoveVector.x * 2);
				}
				else if ((strTab[0] == "right") && (ball.getPosition().x <= tmp.getPosition().x - 2.f) && ((ball.getPosition().y < tmp.getPosition().y + 20.0) && (ball.getPosition().y > tmp.getPosition().y)))
				{
					strTab[0] = "left";
					ballMoveVector.x = ballMoveVector.x - (ballMoveVector.x * 2);
				}
				else
				{
					strTab[1] = "up";
					ballMoveVector.y = ballMoveVector.y - (ballMoveVector.y * 2);
				}
				
			}
			this->bricks.erase(bricks.begin() + i);
			this->points += 50;
		}
	}
	return ballMoveVector;
}


void Bricks::render(sf::RenderWindow* window)
{
	for (int i = 0; i < bricks.size(); i++)
	{
		window->draw(bricks[i]);
	}

}
