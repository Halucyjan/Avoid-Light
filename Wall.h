#pragma once
#include <SFML/Graphics.hpp>

class Wall
{
public:
	Wall(sf::Vector2f _start, sf::Vector2f _end);
	void draw(sf::RenderWindow& window);
private:
	sf::Vector2f start;
	sf::Vector2f end;
	sf::Vertex line[2]{};
};

