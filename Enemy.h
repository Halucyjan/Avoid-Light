#pragma once
#include <SFML/Graphics.hpp>
class Enemy{
public:
	Enemy(sf::Vector2f _pos, float _rad);
	Enemy(sf::Vector2f _pos, sf::Vector2f _end, float _rad);
	void draw(sf::RenderWindow& window);
	float calculateDistance();
	sf::Vector2f calculateMoveVector();
	bool isCloseToEnd();
	void move();
	void update();
	float getRadius() const { return rad; };
	sf::Vector2f getPosition() const { return pos; };
private:
	sf::Vector2f pos;
	float rad, poleRad;
	float movementSpeed{ 0.1f };
	float moveStep;
	sf::Vector2f moveVector;
	float distance, startDistance;
	sf::Color lightColor;
	sf::CircleShape light, pole;
	sf::Vector2f startMovement, endMovement;
};

