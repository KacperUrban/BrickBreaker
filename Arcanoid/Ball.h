#pragma once
#include <SFML/Graphics.hpp>
#include "Bricks.h"
#include <iostream>
#include <string>


class Ball
{
private:
	sf::CircleShape ball;
	float bPosX, bPosY;
	float mPosX, mPosY;
	sf::Vector2f ballMoveVector;
	int counter;
	bool mouseClick;
public:
	std::string* strTab;
	bool end;
	Ball();
	void initBall();
	void checkBound();
	void collisionWithPlayer(sf::Sprite player);
	sf::CircleShape returnBall();
	sf::Vector2f returnBallMoveVector();
	void setBallMoveVector(sf::Vector2f vector);
	void update(sf::Sprite player);
	void render(sf::RenderTarget* target);
};

