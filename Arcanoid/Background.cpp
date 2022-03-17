#include "Background.h"
#include <iostream>
Background::Background()
{
	this->initBackground();
}

void Background::initBackground()
{
	if (!this->tBackground.loadFromFile("texture/breakout_bg.png"))
	{
		std::cout << "Error load from file!" << std::endl;
	}
	this->sBackground.setTexture(this->tBackground);
	this->sBackground.setScale(0.95f, 1.75f);
}

void Background::render(sf::RenderWindow* window)
{
	window->draw(this->sBackground);
}
