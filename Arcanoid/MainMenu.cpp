#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu()
{
	this->initWindow();
	this->initMenu();
}

MainMenu::~MainMenu()
{
	delete window;
}

void MainMenu::initMenu()
{
	if (!this->font.loadFromFile("font/Retroking.ttf"))
	{
		std::cout << "Error load font!";
	}

	if (!this->texture.loadFromFile("texture/breakout_bg.png"))
	{
		std::cout << "Error load image!";
	}
	this->background.setTexture(this->texture);
	this->background.setScale(0.95f, 1.75f);
	this->menu[0].setFont(this->font);
	this->menu[0].setCharacterSize(70);
	this->menu[0].setFillColor(sf::Color::Red);
	this->menu[0].setString("Play");
	this->menu[0].setPosition(sf::Vector2f((this->window->getSize().x / 2) - 100, this->window->getSize().y / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	this->menu[1].setFont(this->font);
	this->menu[1].setCharacterSize(70);
	this->menu[1].setFillColor(sf::Color::White);
	this->menu[1].setString("Levels");
	this->menu[1].setPosition(sf::Vector2f((this->window->getSize().x / 2) - 100, this->window->getSize().y / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	this->menu[2].setFont(this->font);
	this->menu[2].setCharacterSize(70);
	this->menu[2].setFillColor(sf::Color::White);
	this->menu[2].setString("Exit");
	this->menu[2].setPosition(sf::Vector2f((this->window->getSize().x / 2) - 100, this->window->getSize().y / (MAX_NUMBER_OF_ITEMS + 1) * 3));

}

void MainMenu::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(600, 800), "Arcanoid", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void MainMenu::moveUp()
{
	if (this->selectedNumberIndex - 1 >= 0)
	{
		menu[this->selectedNumberIndex].setFillColor(sf::Color::White);
		this->selectedNumberIndex--;
		menu[this->selectedNumberIndex].setFillColor(sf::Color::Red);
	}
}

void MainMenu::moveDown()
{
	if (this->selectedNumberIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[this->selectedNumberIndex].setFillColor(sf::Color::White);
		this->selectedNumberIndex++;
		menu[this->selectedNumberIndex].setFillColor(sf::Color::Red);
	}
}

void MainMenu::update()
{
	sf::Event event;
	while (this->window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyReleased:
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				this->moveUp();
				break;
			case sf::Keyboard::Down:
				this->moveDown();
				break;
			case sf::Keyboard::Return:
				switch (this->GetPressedItem())
				{
				case 0:
				{
					Game game;
					this->window->close();
					game.run();
					break;
				}
				case 1:
					break;
				case 2:
					this->window->close();
					break;
				}
			}
			break;
		case sf::Event::Closed:
			this->window->close();
			break;

		}
	}
}

void MainMenu::render()
{
	this->window->clear(sf::Color(32, 32, 32));
	this->window->draw(this->background);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		this->window->draw(menu[i]);
	}
	this->window->display();
}

void MainMenu::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}
