#pragma once
#include <SFML/Graphics.hpp>

class End
{
public:
	End(float _x, float _y);
	void draw(sf::RenderWindow& window);
	float getRadius() const { return rad; };
	sf::Vector2f getPosition() const { return pos; };
private:
	sf::Vector2f pos;
	sf::CircleShape end;
	float rad{ 30 };
};

