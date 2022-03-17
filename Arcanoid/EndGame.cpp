#include "EndGame.h"

EndGame::EndGame()
{
	this->initWindow();
	this->initEndGame();
}

EndGame::~EndGame()
{
	delete this->window;
}

void EndGame::initEndGame()
{
	std::string tmp = std::to_string(point);
	if (!this->font.loadFromFile("font/times.ttf"))
	{
		std::cout << "Error load font!";
	}

	if (!this->texture.loadFromFile("texture/breakout_bg.png"))
	{
		std::cout << "Error load image!";
	}
	this->background.setTexture(this->texture);
	this->background.setScale(0.95f, 1.75f);
	this->endGame[0].setFont(this->font);
	this->endGame[0].setCharacterSize(70);
	this->endGame[0].setFillColor(sf::Color::Red);
	this->endGame[0].setString("Game Over");
	this->endGame[0].setPosition(sf::Vector2f((this->window->getSize().x / 2) - 150, this->window->getSize().y / 3 - 50));

	this->endGame[1].setFont(this->font);
	this->endGame[1].setCharacterSize(70);
	this->endGame[1].setFillColor(sf::Color::Red);
	this->endGame[1].setString("Your score:");
	this->endGame[1].setPosition(sf::Vector2f((this->window->getSize().x / 2) - 150, this->window->getSize().y / 2 - 50));

	this->endGame[2].setFont(this->font);
	this->endGame[2].setCharacterSize(70);
	this->endGame[2].setFillColor(sf::Color::Red);
	this->endGame[2].setString(tmp);
	this->endGame[2].setPosition(sf::Vector2f((this->window->getSize().x / 2) , this->window->getSize().y / 1 - 300));
}

void EndGame::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(600, 800), "Arcanoid", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void EndGame::update()
{
	sf::Event event;
	while (this->window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			this->window->close();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			this->window->close();
	}
}

void EndGame::render()
{
	this->window->clear(sf::Color(32, 32, 32));
	this->window->draw(this->background);
	for (int i = 0; i < 3; i++)
	{
		this->window->draw(endGame[i]);
	}
	this->window->display();
}

void EndGame::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

