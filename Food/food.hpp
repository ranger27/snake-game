#ifndef FOOD_HPP
#define FOOD_HPP

#include <SFML/Graphics.hpp>
#include "../randomLibrary/random.hpp"
#include <random>

namespace food
{
    class Food
    {
        const int &windowWidth;
        const int &windowHeight;
        // A part of the outside of the size should be invisible
        sf::Vector2u size = sf::Vector2u(40, 40);
        sf::RectangleShape food;

        // to be improved further so that random location
        // doesn't fall into body of snake
        sf::Vector2f findALocation();
        void createFood();

    public:
        Food(const int &windowWidth, const int &windowHeight);
        
        // used to just render the snake
        void renderFood(sf::RenderWindow &window);
    };
}

#endif