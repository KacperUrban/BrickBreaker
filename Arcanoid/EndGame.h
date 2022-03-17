#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Game.h"

class EndGame
{
private:
	sf::Texture texture;
	sf::Sprite background;
	sf::RenderWindow* window;
	sf::Font font;
	sf::Text endGame[3];
public:
	int point;
	EndGame();
	~EndGame();
	void initEndGame();
	void initWindow();
	void update();
	void render();
	void run();
};

