#include "Wall.h"

Wall::Wall(sf::Vector2f _start, sf::Vector2f _end){
	line[0] = _start;
	line[1] = _end;
}

void Wall::draw(sf::RenderWindow& window){
	window.draw(line, 2, sf::Lines);
}
