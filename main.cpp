#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "./Game/game.hpp"
#include "./Food/food.hpp"

const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 800;

int main()
{
    // loading music and font

    // font part
    sf::Font font;
    if (!font.loadFromFile("./assets/NotoSans-Regular.ttf"))
    {
        std::cout << "Font could not be loaded." << std::endl;
        return -1;
    }
    // music part
    sf::Music music;
    if (!music.openFromFile("./assets/background-music.wav"))
        return -1; // error
    music.play();

    game::Game gameObj(WINDOW_WIDTH, WINDOW_HEIGHT, font);
    food::Food fruit(WINDOW_WIDTH, WINDOW_HEIGHT);
    gameObj.player.makeInitialSnake();

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake Game");

    int counterToMove = 0;
    // disable multiple keypressed events.
    window.setKeyRepeatEnabled(false);
    while (window.isOpen())
    {
        window.setFramerateLimit(12);
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
        gameObj.renderScore(window);
        gameObj.player.renderSnake(window);
        if (gameObj.didPlayerEatFood(fruit))
        {
            // create a new food;
            fruit = food::Food(WINDOW_WIDTH, WINDOW_HEIGHT);
        }
        if (gameObj.player.didSnakeHitItself())
        {
            sf::Time delayTime = sf::seconds(2.f);
            sf::sleep(delayTime);
            std::cout << "Game Over " << std::endl;
            while (window.isOpen())
            {
                std::cout << "here1" << std::endl;
                sf::Event e;
                while (window.pollEvent(e))
                {
                    if (e.type == sf::Event::Closed)
                    {
                        window.close();
                    }
                }
                window.clear();
                std::cout << "here2" << std::endl;
                gameObj.renderGameOverScreen(window, font);
                std::cout << "here3" << std::endl;
                window.display();
            }
        }

        window.display();
        counterToMove++;
    }
    return 0;
}