#include <iostream>
#include <SFML/Graphics.hpp>
#include "./Game/game.hpp"
#include "./Food/food.hpp"

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;

int main()
{

    game::Game gameObj(WINDOW_WIDTH, WINDOW_HEIGHT);
    food::Food fruit(WINDOW_WIDTH, WINDOW_HEIGHT);
    gameObj.player.makeInitialSnake();

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake Game");
    int counterToMove = 0;
    // disable multiple keypressed events.
    window.setKeyRepeatEnabled(false);
    while (window.isOpen())
    {
        window.setFramerateLimit(8);
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (e.type == sf::Event::KeyPressed)
            {
                if (e.key.code == sf::Keyboard::Up || e.key.code == sf::Keyboard::Down || e.key.code == sf::Keyboard::Right || e.key.code == sf::Keyboard::Left)
                {
                    gameObj.player.setCurrentDirection(e.key.code);
                }
            }
        }

        window.clear();
        if (counterToMove >= 5)
        {
            counterToMove = 0;
        }
        gameObj.player.moveSnake();
        fruit.renderFood(window);
        gameObj.player.renderSnake(window);
        if(gameObj.didPlayerEatFood(fruit)){
            // create a new food;
            // fruit = food::Food(WINDOW_WIDTH, WINDOW_HEIGHT);
        }
        
        window.display();
        counterToMove++;
    }
    return 0;
}