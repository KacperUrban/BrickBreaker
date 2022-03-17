#pragma once
#include <SFML/Graphics.hpp>
#include "Background.h"
#include "Ball.h"
#include "Player.h"
#include "Bricks.h"
#include "EndGame.h"

class Game
{
private:
	sf::RenderWindow* window;
	Background* background;
	Ball* ball;
	Player* player;
	Bricks* bricks;

public:
	Game();
	~Game();
	void initWindow();
	void init();
	void update();
	void render();
	void run();
};

