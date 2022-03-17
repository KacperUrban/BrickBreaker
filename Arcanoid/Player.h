#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::Texture tPlayer;
	sf::Sprite sPlayer;
	sf::Vector2f playerVector;
	sf::Vector2i mousePosition;
public:
	Player();
	void initPlayer();
	void update(sf::Event event, sf::RenderWindow* window);
	sf::Sprite returnPlayer();
	void render(sf::RenderWindow* window);

};

