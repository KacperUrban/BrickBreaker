#include "Game.h"
#include <iostream>

Game::Game()
{
	this->initWindow();
	this->init();
}

Game::~Game()
{
	delete window;
	delete background;
	delete ball;
	delete player;
	delete bricks;
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(600, 800), "Arcanoid", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void Game::init()
{
	this->background = new Background();
	this->ball = new Ball();
	this->player = new Player();
	this->bricks = new Bricks();
}

void Game::update()
{
	sf::Event e;
	while (window->pollEvent(e))
	{
		if (e.type == sf::Event::Closed)
			this->window->close();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			this->window->close();
		player->update(e, this->window);
	}
	ball->update(player->returnPlayer());
	ball->setBallMoveVector(bricks->collisionWithBall(ball->returnBall(), ball->returnBallMoveVector(), ball->strTab));
	ball->collisionWithPlayer(player->returnPlayer());
	if (ball->end == true)
	{
		this->window->close();
		EndGame endGame;
		endGame.point = bricks->returnPoints();
		endGame.run();
	}
}

void Game::render()
{
	this->window->clear();
	this->background->render(this->window);
	this->ball->render(this->window);
	this->player->render(this->window);
	this->bricks->render(this->window);
	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}
