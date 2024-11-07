#include <SFML/Graphics.hpp>
#include "Player.h"
#include "wall.h"
#include "Enemy.h"
#include "End.h"
#include <iostream>

//screeen size
const int WIDTH{ 1920 };
const int HEIGHT{ 1080 };


int main()
{
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "error font";
    }
    sf::Text text;
    // select the font
    text.setFont(font); // font is a sf::Font
    // set the string to display
    text.setString("wygrales!");
    // set the character size
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::Red);
    text.setPosition(500, 500);

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "latarnia");
    bool gameEnd{ false };

    Player player1(100,100);
    End end1(WIDTH / 2, HEIGHT / 2);
    std::vector<Enemy> enemies;
    
    Enemy enemy1(sf::Vector2f(500, 500), sf::Vector2f(1200, 500), 100);
    Enemy enemy2(sf::Vector2f(500, 300), sf::Vector2f(1200, 300), 90);
    Enemy enemy3(sf::Vector2f(900, 500), sf::Vector2f(1000, 800), 110);
    Enemy enemy4(sf::Vector2f(1200, 700), sf::Vector2f(500, 700), 105);
    enemies.push_back(enemy1);
  /*  Wall(sf::Vector2f(400, 0), sf::Vector2f(400, 400));
    std::vector<Wall> walls;
    walls.push_back(Wall(sf::Vector2f(400, 0), sf::Vector2f(400, 400)));
    walls.push_back(Wall(sf::Vector2f(400, 400), sf::Vector2f(600, 400)));*/
    //std::cout << enemy1.calculateDistance();

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(!gameEnd){
            player1.update();
            enemy1.update(); 
            enemy2.update();
            enemy3.update();
            enemy4.update();
        }
        window.draw(text);

        if (player1.hitEnemy(enemy1.getPosition(), enemy1.getRadius())) {
            player1.returnToStart();
        }
        if (player1.hitEnemy(enemy2.getPosition(), enemy2.getRadius())) {
            player1.returnToStart();
        }
        if (player1.hitEnemy(enemy3.getPosition(), enemy3.getRadius())) {
            player1.returnToStart();
        }
        if (player1.hitEnemy(enemy4.getPosition(), enemy4.getRadius())) {
            player1.returnToStart();
        }
        
        
        

        window.clear(sf::Color(40, 40, 40));
        end1.draw(window);
        player1.draw(window);
        enemy1.draw(window);
        enemy2.draw(window);
        enemy3.draw(window);
        enemy4.draw(window);
        if (player1.hitEnemy(end1.getPosition(), end1.getRadius())) {
            gameEnd = true;
            window.draw(text);
        }
        //for (Wall wall : walls) {
        //    wall.draw(window);
        //}
        window.display();
    }

    return 0;
}