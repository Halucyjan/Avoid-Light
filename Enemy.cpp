#include "Enemy.h"

Enemy::Enemy(sf::Vector2f _pos, float _rad)
	:pos(_pos), rad(_rad){
	lightColor = sf::Color(255, 255, 0, 100);

	//set light
	light.setRadius(rad);
	light.setFillColor(lightColor);
	light.setPosition(pos);

	//set pole inside light
	poleRad = 10;
	pole.setRadius(poleRad);
	pole.setFillColor(sf::Color::Black);
	pole.setPosition(pos + (sf::Vector2f(rad - poleRad,rad - poleRad)));

	//set movement vectors
	startMovement = pos;
	endMovement = pos;
}

Enemy::Enemy(sf::Vector2f _pos, sf::Vector2f _end, float _rad)
	:pos(_pos), endMovement(_end), rad(_rad) {
	lightColor = sf::Color(255, 255, 0, 100);

	//set light
	light.setRadius(rad);
	light.setFillColor(lightColor);
	light.setPosition(pos);

	//set pole inside light
	poleRad = 10;
	pole.setRadius(poleRad);
	pole.setFillColor(sf::Color::Black);
	pole.setPosition(pos + (sf::Vector2f(rad - poleRad, rad - poleRad)));

	//set movement vectors
	startMovement = pos;
	startDistance = calculateDistance();
	moveVector = calculateMoveVector();
}

void Enemy::draw(sf::RenderWindow& window){
	window.draw(light);
	window.draw(pole);
}

float Enemy::calculateDistance(){
	float tempX = pow((pos.x - endMovement.x), 2);
	float tempY = pow((pos.y - endMovement.y), 2);
	distance = sqrt(tempX + tempY);
	return distance;
}

sf::Vector2f Enemy::calculateMoveVector(){
	moveStep = distance / movementSpeed;
	moveVector = sf::Vector2f(endMovement - startMovement) / distance * movementSpeed;
	return moveVector;
}

bool Enemy::isCloseToEnd()
{
	if (this->calculateDistance() < 1) {
		return true;
	}
	return false;
}

void Enemy::move(){
	pos += moveVector;
	light.setPosition(pos);
	pole.setPosition(pos + (sf::Vector2f(rad - poleRad, rad - poleRad)));
}

void Enemy::update(){
	this->move();
	if (isCloseToEnd())
	{
		sf::Vector2f temp = startMovement;
		this->startMovement = endMovement;
		this->endMovement = temp;
		moveVector = -moveVector;
	}

}
