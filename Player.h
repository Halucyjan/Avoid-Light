#pragma once
#include <SFML/Graphics.hpp>

class Player{
public:
	Player();
	Player(float _x, float _y);

	void movement();
	void draw(sf::RenderWindow& window);
	void update();
	bool hitEnemy(sf::Vector2f enemyPos, float enemyRad);
	void returnToStart();
private:
	const float sqrt2{ 1.4142f }; //square root of 2
	float rad{ 10 };
	const float characterMoveSpeed{ 0.5f };

	sf::Vector2f pos, startPos; // player position
	sf::CircleShape character;

	float hp{ 100 };

};