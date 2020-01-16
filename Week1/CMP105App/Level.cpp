#include "Level.h"

int theta = 0;
Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	// initialise game objects

	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error Loading Font\n";
	}

	
	text.setPosition(589, 5);
	text.setFont(font);
	text.setString("Hello World");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);

	rect.setSize(sf::Vector2f(50, 20));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Red);

	rect1.setSize(sf::Vector2f(100, 100));
	rect1.setPosition(300, 300);
	rect1.setFillColor(sf::Color::Red);

	rect2.setSize(sf::Vector2f(60, 60));
	rect2.setPosition(320, 320);
	rect2.setFillColor(sf::Color::Blue);

	rect3.setSize(sf::Vector2f(20, 20));
	rect3.setPosition(340, 340);
	rect3.setFillColor(sf::Color::Green);

	rect4.setSize(sf::Vector2f(100, 100));
	rect4.setOrigin(100,100);
	rect4.setFillColor(sf::Color::Magenta);

	circle.setRadius(50);
	circle.setPosition(550, 285);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineThickness(2.f);
	circle.setOutlineColor(sf::Color::Red);

	circle2.setRadius(20);
	circle2.setFillColor(sf::Color::Green);


}

Level::~Level()
{
	
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	sf::Vector2u pos = window->getSize();
	rect4.setPosition((pos.x), (pos.y));

	if (theta >= 360)
	{
		theta = 0;
	}

	float x = 50 * cos(theta);
	float y = 50 * sin(theta);

	circle2.setPosition((600 + x), (200 + y));

	theta++;

}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(rect);

	window->draw(circle);
	window->draw(circle2);

	window->draw(rect1);
	window->draw(rect2);
	window->draw(rect3);
	window->draw(rect4);

	window->draw(text);

	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}