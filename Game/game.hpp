#ifndef GAME_HPP
#define GAME_HPP

#include "../snake/snake.hpp"
#include "../Food/food.hpp"
#include <SFML/Graphics.hpp>

namespace game
{
    class Game
    {
        int score;
        sf::Text scoreText;
        const int &windowWidth;
        const int &windowHeight;

    public:
        // FIXME: look if the player can be made private to restrict data
        snake::Snake player;
        Game(const int &windowWidth, const int &windowHeight,sf::Font& font);
        bool didPlayerEatFood(food::Food & );
        void createScore(sf::Font & font);
        void renderScore(sf::RenderWindow &window);
        void renderGameOverScreen(sf::RenderWindow &window,sf::Font& font);
    };
}

#endif