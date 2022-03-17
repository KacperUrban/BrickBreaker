#pragma once
#include <SFML/Graphics.hpp>
class Background
{private:
	sf::Texture tBackground;
	sf::Sprite sBackground;
public:
	Background();
	void initBackground();
	void render(sf::RenderWindow* window);
};

