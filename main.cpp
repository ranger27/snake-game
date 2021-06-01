#include <iostream>
#include <SFML/Graphics.hpp>
#include "./Game/game.hpp"
 
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;


int main()
{

    game::Game gameObj(WINDOW_WIDTH,WINDOW_HEIGHT);
    gameObj.player.makeInitialSnake();

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake Game");
    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        gameObj.player.renderSnake(window);
        window.display();
    }
    return 0;
}