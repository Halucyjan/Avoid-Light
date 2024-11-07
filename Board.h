#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Wall.h"
#include "Enemy.h"

class Board{
public:
	Board();
	void draw(sf::RenderWindow& window);
	void update();
	void updateAndDraw(sf::RenderWindow& window);
private:

};

