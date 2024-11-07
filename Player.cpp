#include "Player.h"

Player::Player(){
    pos.x = 0;
    pos.y = 0;
    startPos = pos;
    character.setRadius(rad);
    character.setFillColor(sf::Color::Blue);
    character.setPosition(pos);
}

Player::Player(float _x, float _y){
    pos.x = _x;
    pos.y = _y;
    startPos = pos;
    character.setRadius(rad);
    character.setFillColor(sf::Color::Blue);
    character.setPosition(pos);
}

void Player::movement(){
    //movement in diagonal line
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right) and sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up)) {
        //character.move(sf::Vector2f(1 / sqrt2 * characterMoveSpeed, -1 / sqrt2 * characterMoveSpeed));
        pos += sf::Vector2f(1 / sqrt2 * characterMoveSpeed, -1 / sqrt2 * characterMoveSpeed);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right) and sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down)) {
        //character.move(sf::Vector2f(1 / sqrt2 * characterMoveSpeed, 1 / sqrt2 * characterMoveSpeed));
        pos += sf::Vector2f(1 / sqrt2 * characterMoveSpeed, 1 / sqrt2 * characterMoveSpeed);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left) and sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up)) {
        //character.move(sf::Vector2f(-1 / sqrt2 * characterMoveSpeed, -1 / sqrt2 * characterMoveSpeed));
        pos += sf::Vector2f(-1 / sqrt2 * characterMoveSpeed, -1 / sqrt2 * characterMoveSpeed);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left) and sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down)) {
        //character.move(sf::Vector2f(-1/sqrt2 * characterMoveSpeed, 1 / sqrt2 * characterMoveSpeed));
        pos += sf::Vector2f(-1 / sqrt2 * characterMoveSpeed, 1 / sqrt2 * characterMoveSpeed);
    }

    //movement in straight line
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right)) {
        //character.move(sf::Vector2f(characterMoveSpeed, 0));
        pos += sf::Vector2f(characterMoveSpeed, 0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left)) {
        //character.move(sf::Vector2f(-characterMoveSpeed, 0));
        pos += sf::Vector2f(-characterMoveSpeed, 0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up)) {
        //character.move(sf::Vector2f(0, -characterMoveSpeed));
        pos += sf::Vector2f(0, -characterMoveSpeed);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down)) {
        //character.move(sf::Vector2f(0, characterMoveSpeed));
        pos += sf::Vector2f(0, characterMoveSpeed);
    }
    //todo
    //problem with opposite input
}

void Player::draw(sf::RenderWindow& window){
    window.draw(character);
}

void Player::update(){
    this->movement();
    character.setPosition(pos);
}

bool Player::hitEnemy(sf::Vector2f enemyPos, float enemyRad){
    float maxRad = rad + enemyRad;
    float tempX{ pos.x + rad - (enemyPos.x + enemyRad) };
    float tempY{ pos.y + rad - (enemyPos.y + enemyRad) };
    tempX = pow(tempX, 2);
    tempY = pow(tempY, 2);
    float result = sqrt(tempX + tempY);
    if (result < maxRad)
        return true;
    return false;
}

void Player::returnToStart(){
    pos = startPos;
}
