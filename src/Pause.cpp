#include "../includes/Pause.hpp"
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <stdio.h>


Pause::Pause(float width, float height)
{
	if (!font.loadFromFile("./fonts/japanese.ttf"))
	{
		printf("erreur can not open fonts file");
	}

	pause[0].setFont(font);
	pause[0].setFillColor(sf::Color::Red);
	pause[0].setString("Resume");
	pause[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_PAUSE + 1) * 1));

	pause[1].setFont(font);
	pause[1].setFillColor(sf::Color::White);
	pause[1].setString("Exit");
	pause[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_PAUSE + 1) * 2));

	selectedIndex = 0;
}


Pause::~Pause()
{
}

void Pause::draw(sf::RenderWindow &app)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS_PAUSE; i++)
	{
		app.draw(pause[i]);
	}
}

void Pause::MoveUp()
{
	if (selectedIndex - 1 >= 0)
	{
		pause[selectedIndex].setFillColor(sf::Color::White);
		selectedIndex--;
		pause[selectedIndex].setFillColor(sf::Color::Red);
	}
}

void Pause::MoveDown()
{
	if (selectedIndex + 1 < MAX_NUMBER_OF_ITEMS_PAUSE)
	{
		pause[selectedIndex].setFillColor(sf::Color::White);
		selectedIndex++;
		pause[selectedIndex].setFillColor(sf::Color::Red);
	}
}