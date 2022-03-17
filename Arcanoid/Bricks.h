#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Bricks
{
private:
	sf::RectangleShape brick;
	sf::Vector2f brickVectorSize;
	std::vector <sf::RectangleShape> bricks;
	int points;
public:
	Bricks();
	void initBrick();
	int returnPoints();
	sf::Vector2f collisionWithBall(sf::CircleShape ball, sf::Vector2f ballMoveVector, std::string* strTab);
	void render(sf::RenderWindow* window);
};


