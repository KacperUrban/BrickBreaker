#pragma once
#include "SFML/Graphics.hpp"
#include "Game.h"
#define MAX_NUMBER_OF_ITEMS 3
class MainMenu
{
private:
	int selectedNumberIndex;
	sf::Texture texture;
	sf::Sprite background;
	sf::RenderWindow* window;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
public:
	MainMenu();
	~MainMenu();
	int GetPressedItem() { return this->selectedNumberIndex; }
	void initMenu();
	void initWindow();
	void moveUp();
	void moveDown();
	void update();
	void render();
	void run();

};