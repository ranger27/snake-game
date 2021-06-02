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
        int lives;

    public:
        // FIXME: look if the player can be made private to restrict data
        snake::Snake player;
        Game(const int &windowWidth, const int &windowHeight);
        bool didPlayerEatFood(food::Food & );
    };
}

#endif